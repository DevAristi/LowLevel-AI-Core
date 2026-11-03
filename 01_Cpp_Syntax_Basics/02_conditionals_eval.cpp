#include <iostream>

int main(){
    int age;
    float gpa;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your GPA (0.0 - 10.0): ";
    std::cin >> gpa;

    if (gpa < 0.0f || gpa > 10.0f) {
        std::cout << "[ERROR] Invalid GPA entered. \n";
        return 1;
    }
    else if (age < 5 || age > 100)
    {
        std::cout << "[ERROR] Your age must be wrong. \n";
    }
    else {
        std::cout << "Your age is " << age << " and your GPA is: " << gpa << '\n';
    }
    return 0;
}