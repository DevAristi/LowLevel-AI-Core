#include <iostream>

int main() {
    int age;
    float hght;
    char in_name;
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your height (in meters): ";
    std::cin >> hght;

    std::cout << "Enter your initial: ";
    std::cin >> in_name;

    std::cout << "\n--- User Profile Summary ---\n";
    std::cout << "Age: " << age << " years old\n";
    std::cout << "Height: " << hght << " m\n";
    std::cout << "Initial: " << in_name << '\n';

    return 0;
}