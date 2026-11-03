# Low-Level AI Core & Systems Foundations

A low-level engineering roadmap tracking the journey from bare-metal C++ systems programming to custom high-throughput LLM inference engines and GPU computing on local NVIDIA hardware (RTX 3080 + Ryzen 9 5900X).

---

## 🎯 Architecture & Hardware Specifications

- **Host CPU:** AMD Ryzen 9 5900X (12C/24T, 3.7 GHz base / 4.8 GHz boost, 64 MB L3 Cache, 32 KB L1D per core)
- **Target GPU:** NVIDIA GeForce RTX 3080 (Ampere architecture, 8704 CUDA Cores, 10 GB GDDR6X, 760 GB/s bandwidth)
- **Environment:** Ubuntu Linux (WSL2), `g++` (C++20 standard), NVIDIA CUDA Toolkit (`nvcc`), `make`/`cmake`, NVIDIA Nsight Systems.

---

## 🔬 Phase 0: Foundations & Hardware Mapping

### Module 01: Memory Layout & Primitive Footprints

#### 1. Fundamental Types Footprint (`memory_types.cpp`)
Data movement dominates modern inference latency. Minimizing parameter footprint directly mitigates PCIe 4.0 and DRAM bandwidth saturation:

| Primitive Type | Size (Bytes) | Alignment | Relevance to AI Systems / Compute |
| :--- | :---: | :---: | :--- |
| `char` / `int8_t` | 1 | 1 | INT8 Quantization (SmoothQuant, dynamic range activation) |
| `float` | 4 | 4 | Standard IEEE 754 Single Precision (FP32) |
| `double` | 8 | 8 | Double precision (FP64) — avoid in inference pipelines due to 2x memory bandwidth overhead |
| `bool` | 1 | 1 | Flag masking; causes memory overhead if uncompressed |

**Build & Run:**
```bash
g++ -std=c++20 -Wall -Wextra -O2 01_Memory_Layout/memory_types.cpp -o memory
./memory
```

#### 2. Hardware Bounds & Branching Overhead (`branching_limits.cpp`)
Exploration of arithmetic overflow conditions without triggering Undefined Behavior (UB), simulating warp divergence and branch prediction mechanics:

- **Signed 32-bit integer boundary:** $[-2^{31}, 2^{31}-1] \rightarrow [-2,147,483,648, 2,147,483,647]$
- **Branch misprediction penalty:** 12–20 CPU cycles on Zen 3 architecture.
- **Warp divergence risk:** Execution serialization in GPU warps (32 threads).

**Build & Run:**
```bash
g++ -std=c++20 -Wall -Wextra -O2 01_Memory_Layout/branching_limits.cpp -o limits
./limits
```

---

## 📈 Roadmap & Milestones

- [x] Primitive type footprint audit (`sizeof`)
- [ ] Safe arithmetic boundary checks (`branching_limits.cpp`)
- [ ] Cache lines & locality analysis (Row-Major vs Col-Major contiguous access)
- [ ] Manual dynamic allocation (`new` / `delete[]`) vs stack layout
- [ ] L1D Cache blocking (GEMM Tiling)
