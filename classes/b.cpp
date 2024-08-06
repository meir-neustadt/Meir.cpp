#include "meir.h"

void qs(char* items, int left, int right) {
    int i, j;
    char x, temp;

    i = left, j = right;         // initialize 2 edges
    x = items[(left+right)/2];   // x to the center

    do {
        while(items[i]<x && i<right) i++; // i = 1st e>=x
        while(items[j]>x && j>left) j--;  // j = last e<=x
        if(i<=j){
            swap(items[i], items[j]);
            i++; j--;
        }
    } while (i<=j);

    if(j>left) qs(items, left, j);
    if(i<right) qs(items, i, right);
}


int main() {
    char string[] {"$O6%Xxvm-j60"};
    printL(string);
    qs(string, 0, 9);
    printL(string);
    return 0;
}