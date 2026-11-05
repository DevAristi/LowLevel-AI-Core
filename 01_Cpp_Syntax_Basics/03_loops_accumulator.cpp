#include <iostream>

int main() {
    int n;
    std::cout << "Enter a number (higher than 0): ";
    std::cin >> n;
    if (n <= 0){
        std::cout << "[ERROR] The number is lower than 0" << '\n';
        return 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    unsigned long long factorial = 1;
    int temp = n;
    while (temp > 1) {
        factorial *= temp;
        --temp;
    }

    std::cout << "Sum from 1 to " << n << ": " << sum << '\n';
    std::cout << "Factorial of " << n << " (" << n << "!): " << factorial << '\n';

    return 0;
}