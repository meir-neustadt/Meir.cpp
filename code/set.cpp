#include <iostream>
#include <cstdlib>


// functions declaration

int combinations(int n, int k);
int setStar(int elements);


// main

int main(int argc, char* argv[]){

    if (argc < 2) return 1;
    
    int elements = std::atoi(argv[1]);
    if (elements < 0) return 2;

    std::cout << setStar(elements) << std::endl;

    return 0;
}


// implementation

int combinations(int n, int k) {
    if (k > n-k) k = n-k;   // symmetry property
    int combs = 1;
    for (int i = 0; i < k; ++i) {
        combs = combs * (n-i)/(i+1);
    }
    return combs;
}

int setStar(int elements){
    int sets = 1;   // null set
    int elemInSubSet = elements;
    while (elemInSubSet){
        sets += combinations(elements, elemInSubSet--);
    };
    return sets; 
}