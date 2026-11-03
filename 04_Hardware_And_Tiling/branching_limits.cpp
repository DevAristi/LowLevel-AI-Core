#include <iostream>
#include <limits>

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Enter first integer: ";
    std::cin >> a;
    std::cout << "Enter second integer: ";
    std::cin >> b;

    constexpr int max_limit = std::numeric_limits<int>::max();
    constexpr int min_limit = std::numeric_limits<int>::min();

    // Check for positive or negative overflow before executing addition
    if ((b > 0 && a > max_limit - b) || (b < 0 && a < min_limit - b)) {
        std::cout << "[ERROR] Arithmetic Overflow Detected: Operation aborted.\n";
    } else {
        std::cout << "[OK] Safe addition: Result = " << (a + b) << '\n';
    }

    return 0;
}