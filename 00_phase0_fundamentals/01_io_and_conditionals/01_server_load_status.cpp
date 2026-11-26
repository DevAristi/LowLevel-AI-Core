#include <iostream>

int main() {
    double val{0.0};
    std::cin >> val;

    if (val < 0.0 || val > 100.0) {
        std::cout << "Invalid\n";
    } else if (val < 50.0) {
        std::cout << "Normal\n";
    } else if (val < 85.0) {
        std::cout << "Warning\n";
    } else {
        std::cout << "Critical\n";
    }
    
    return 0;
}