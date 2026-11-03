#include <iostream>

int main() {
    std::cout << "--- Memory Audit (Bytes) ---" << '\n';
    
    // std::endl forces a buffer flush which is slow.
    // Get used to using '\n' for simple line breaks in performance-critical code.
    std::cout << "Size of int: " << sizeof(int) << '\n';
    std::cout << "Size of float (FP32): " << sizeof(float) << '\n';
    std::cout << "Size of double (FP64): " << sizeof(double) << '\n';
    std::cout << "Size of char (INT8 equivalent): " << sizeof(char) << '\n';
    std::cout << "Size of bool: " << sizeof(bool) << '\n';

    return 0;
}