#include <iostream>
#include "meir.h"

#define t "  "

template <typename T>

T Max(T num1, T num2){
    return (num1 > num2 ? num1 : num2);
}

int main() {
    int a {30};
    switch (a)
    {
    case 30:
        printL(20);
    case 20:
        printL(10);
        break;    
    default:
        break;
    }
    std::cout << Max(2,7) << t;
    std::cout << Max(3.456,7/2.0);
    printL(333);
}