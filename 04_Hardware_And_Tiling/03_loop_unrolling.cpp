#include <iostream>
#include <chrono>

int main() {
    constexpr size_t N = 100'000'000;
    
    // Naive single-accumulator loop
    auto start_naive = std::chrono::high_resolution_clock::now();
    uint64_t sum_naive = 0;
    for (size_t i = 0; i < N; ++i) {
        sum_naive += 1;
    }
    auto end_naive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> naive_ms = end_naive - start_naive;

    // Manual 4-way unrolled loop
    auto start_unrolled = std::chrono::high_resolution_clock::now();
    uint64_t acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
    for (size_t i = 0; i < N; i += 4) {
        acc0 += 1;
        acc1 += 1;
        acc2 += 1;
        acc3 += 1;
    }
    uint64_t sum_unrolled = acc0 + acc1 + acc2 + acc3;
    auto end_unrolled = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> unrolled_ms = end_unrolled - start_unrolled;

    std::cout << "--- Loop Optimization Benchmark (" << N << " elements) ---\n";
    std::cout << "Naive loop time:     " << naive_ms.count() << " ms | Sum: " << sum_naive << '\n';
    std::cout << "4-way unrolled time: " << unrolled_ms.count() << " ms | Sum: " << sum_unrolled << '\n';

    return 0;
}