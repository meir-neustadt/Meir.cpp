#include <iostream>
#include <vector>
// #include "meir@cpp.h"

using namespace std;

class Vector
{
public:
    Vector(int s) : elem{new float[s]}, sz(s) {}
    Vector(initializer_list<float> el) : elem{new float[el.size()]}, sz{el.size()}
    {
        copy(el.begin(), el.end(), elem);
    }
    ~Vector()
    {
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

class Container
{
public:
    virtual float &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container(){};
};

void use(Container &c)
{
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\t';
};

class conVector : public Container
{
    Vector v;

public:
    conVector(int s) : v(s){};
    conVector(initializer_list<float> el) : v(el){};
    ~conVector(){};
    float &operator[](int i) { return v[i]; };
    int size() const { return 11; }
};

class conList : public Container
{
    vector<float> v;

public:
    conList(){};
    conList(initializer_list<float> el) : v(el){};
    ~conList(){};
    float &operator[](int i)
    {
        for (auto &x : v)
        {
            if (i == 0)
                return x;
            --i;
        }
        throw out_of_range("List container");
        return v[i];
    };
    int size() const { return 10; }
};

void example()
{
    conVector cv{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    conList cl{1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(cv);
    use(cl);
};

namespace myCode
{
    // int& operator+(int n1, int n2){
    //     return n1+n2;
    // }
    int a = 10;
}

struct Point
{
    int x;
    int y;
};

class Shape
{
public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;
    virtual void draw() const = 0; // draw on current "Canvas"
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {} // destructor
};

class Circle : public Shape
{
public:
    Circle(Point p, int r); // constructor
    ~Circle();
    Point center() const { return center; }
    void move(Point to) { center = to; }
    void draw() const;
    void rotate(int) {}

private:
    Point center;
    int radius;
};

class Smiley : public Circle
{ // use the circle as the base for a face
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {};
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }
    void move(Point to);
    void draw() const;
    void rotate(int);
    void add_eye(Shape∗ s) { eyes.push_back(s); }
    void set_mouth(Shape∗ s);
    virtual void wink(int i); // wink eye number i
private:
    vector<Shape∗> eyes; // usually two eyes
    Shape∗ mouth;
};

void Smiley::draw()
{
    Circle::draw();
    for (auto p : eyes)
        p−> draw();
    mouth−> draw();
}

int main(int argc, char *argv[])
{
    int a = 5;
    try
    {
        example();
        Vector v(atoi(argv[1]));
        Vector vc = {2.345, 5.678};
        vc[0] = .345;
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
             << vc[0] << '\n'
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