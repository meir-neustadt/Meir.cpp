#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(int s) : elem{new float[s]}, sz{s} {}
    float &operator[](int i) { return elem[i]; }
    int size() { return sz; }

    // private:
    float *elem; // pointer to the elements
    int sz;      // the number of elements
};

int main()
{
    Vector v(5);
    v.elem[2] = 5.789;
    cout << v[2];
}