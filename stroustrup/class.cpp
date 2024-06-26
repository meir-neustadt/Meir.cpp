#include <iostream>
// #include "meir@cpp.h"

using namespace std;

class Vector
{
public:
    Vector(int s) : elem{new float[s]}, sz{s} {}
    Vector(initializer_list<float> el) : elem{new float[el.size()]}, sz{el.size()} {
        copy(el.begin(), el.end(), elem);
    }
    ~Vector(){
        delete[] elem;
    }
    float &operator[](int i)
    {
        if (i < 0 || sz <= i)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    }
    int size() { return sz; }

private:
    float *elem; // pointer to the elements
    int sz;      // the number of elements
};

namespace myCode
{
    // int& operator+(int n1, int n2){
    //     return n1+n2;
    // }
    int a = 10;
}

int main(int argc, char *argv[])
{
    int a = 5;
    try
    {
        Vector v(atoi(argv[1]));
        Vector vc = {2.345,5.678};
        v[1] = 5.789;
        try
        {
            v[8] = 7;
        }
        catch (out_of_range &e)
        {
            cout << e.what() << '\n';
        }

        using namespace myCode;
        cout << v[1] << '\n'
             << a << '\n'
             << myCode::a;
    }
    catch (length_error &e)
    {
        cout << e.what() << '\n';
    }
    catch (bad_alloc &e)
    {
        cout << e.what() << '\n';
    }
}