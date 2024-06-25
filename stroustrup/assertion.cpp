#include <iostream>

constexpr float C = 299792.458; // Speed of light in km/s

void f()
{
    constexpr float local_max = 160.0 / (60 * 60); // Convert 160 km/h to km/s
    static_assert(local_max < C, "can't go that fast"); 
    static_assert(sizeof(int)==4, "sizof int isn't 8");
}

int main(){
   f();
   std::cout << "Function executed successfully.\n";
   return 0;
}
