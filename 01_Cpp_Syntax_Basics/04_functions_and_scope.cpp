#include <iostream>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int computeScale(int val, int factor){
    return val * factor;
}
double computeScale(double val, double factor){
    return val * factor;
}

int main (){
    int x = 10;
    int y = 20;
    std::cout << "Inicial -> x: " << x << ", y: " << y << '\n';

    swapByValue(x, y);
    std::cout << "Tras swapByValue -> x: "<< x << ", y: " << y << '\n';

    swapByReference(x, y);
    std::cout << "Tras swapByReference -> x: "<< x << ", y: " << y << '\n';

    std::cout << "Scale int (5 * 3): " << computeScale(5, 3) << '\n';
    std::cout << "Scale double (2.5 * 4.0): " << computeScale(2.5, 4.0) << '\n';
    
    return 0;
}