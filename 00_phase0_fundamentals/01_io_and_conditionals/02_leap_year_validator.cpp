#include <iostream>

int main() {
    int year{0};
    std::cin >> year;

    if (year <= 0) {
        std::cout << "Invalid Year\n";
    } else if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        std::cout << "Leap Year\n";
    } else {
        std::cout << "Common Year\n";
    }
    
    return 0;
}