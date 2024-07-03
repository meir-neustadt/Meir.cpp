#include <iostream>

#define s " "
#define t "  "

#define swap(a, b) { auto temp = (a); (a) = (b); (b) = temp; }
#define print(a) { std::cout << (a) << std::endl; }
#define count(increment) { counter += increment; }
#define end(act) { std::cout << "The count of " << act << " is " << counter << std::endl; }

int counter {0};