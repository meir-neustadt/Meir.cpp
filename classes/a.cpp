#include <iostream>

#define t "  "

template <typename T>

T Max(T num1, T num2){
    return (num1 > num2 ? num1 : num2);
}

int main() {
    std::cout << Max(2,7) << t;
    std::cout << Max(3.456,7/2.0);
}