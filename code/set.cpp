#include <iostream>
#include <cstdlib>
#include <chrono>

#define print(data) std::cout << (data) << std::endl


// functions declaration

int combinations(int n, int k);
long long subSets(int elements);


// main

int main(int argc, char* argv[]){
    if (argc < 2) {print("Number of elements not found"); return 1;}
    
    int elements = std::atoi(argv[1]);
    if (elements < 0) {print("A set with negative number of elements doesn't exist"); return 2;}

    auto start = std::chrono::high_resolution_clock::now();
    print(subSets(elements));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;

    return 0;
}


// implementation

int combinations(int n, int k) {
    int combs = 1;
    for (int i = 0; i < k; ++i) {
        combs = combs * (n-i)/(i+1);
    }
    return combs;
}

long long subSets(int elements){
    // sets initializes with null set, and with n set if exist
    long long subsets = elements ? 2 : 1;

    int halfElems = (elements-1)/2;
    int elemsInCombination = 1;

    while (elemsInCombination <= halfElems){
        subsets += combinations(elements, elemsInCombination++) * 2;
    };
    if (elements%2==0) subsets += combinations(elements, elemsInCombination);

    return subsets; 
}