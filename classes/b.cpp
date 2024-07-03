#include "meir.h"

void qs(char* items, int left, int right) {
    int i, j;
    char x, temp;

    i = left, j = right;
    x = items[(left+right)/2];

    count(8);

    do {
        while(items[i]<x && i<right) i++;
        while(items[j]>x && j>left) j--;
        if(i<=j){
            swap(items[i], items[j]);
            i++; j--;
        } 
    } while (i<=j);

    if(j>left) qs(items, left, j);
    if(i<right) qs(items, i, right);
}


int main() {
    char string[] {"1234567890"};
    print(string);
    qs(string, 0, 9);
    print(string);
    end("qs");
    return 0;
}