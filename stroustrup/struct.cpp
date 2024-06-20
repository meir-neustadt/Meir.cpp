#include <iostream>
#include <cstdlib>

using namespace std;

struct Vector
{
    int sz;
    float *elem;
};

void vector_init(Vector &v, int s)
{
    v.elem = new float[s];
    v.sz = s;
}

void vector_free(Vector& v) {
    delete[] v.elem;  // Free memory
}

float read_and_sum(int s)
{
    Vector v;
    vector_init(v, s); // allocate s elements for v

    for (int i = 0; i != s; ++i)
    {
        cout << "Enter a number:\t";
        cin >> v.elem[i]; // read into elements
    }

    float sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i]; // take the sum of the elements

    vector_free(v);
    
    return sum;
}

int main(int argc, char* argv[]) {

    int s = atoi(argv[1]);

    cout << read_and_sum(atoi(argv[1])) << endl;

    return 0;
}







