#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

class Vector
{
public:
    Vector(int s) : elem{new float[s]}, sz(s) {}
    Vector(initializer_list<float> el) : elem{new float[el.size()]}, sz{static_cast<int>(el.size())}
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
    int size() const { return sz; } // Marked as const

private:
    float *elem; // pointer to the elements
    int sz;      // the number of elements
};

class Container
{
public:
    virtual float &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

void use(Container &c)
{
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\t';
    cout << endl;
}

class conVector : public Container
{
    Vector v;

public:
    conVector(int s) : v(s) {}
    conVector(initializer_list<float> el) : v(el) {}
    ~conVector() {}
    float &operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

class conList : public Container
{
    vector<float> v;

public:
    conList() {}
    conList(initializer_list<float> el) : v(el) {}
    ~conList() {}
    float &operator[](int i)
    {
        for (auto &x : v)
        {
            if (i == 0)
                return x;
            --i;
        }
        throw out_of_range("List container");
    }
    int size() const { return static_cast<int>(v.size()); }
};

void example()
{
    conVector cv{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    conList cl{1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(cv);
    use(cl);
}

namespace myCode
{
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
    Circle(Point p, int r) : center_{p}, radius_{r} {} // constructor
    ~Circle() {}
    Point center() const override { return center_; }
    void move(Point to) override { center_ = to; }
    void draw() const override { cout << "Drawing Circle at (" << center_.x << ", " << center_.y << ") with radius " << radius_ << endl; }
    void rotate(int) override {}

private:
    Point center_;
    int radius_;
};

class Smiley : public Circle
{ // use the circle as the base for a face
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
    ~Smiley() override
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }
    void move(Point to) override
    {
        Circle::move(to);
        for (auto p : eyes)
            p->move(to);
    }
    void draw() const override
    {
        Circle::draw();
        for (auto p : eyes)
            p->draw();
        if (mouth) {
            mouth->draw();
        }
    }
    void rotate(int angle) override
    {
        for (auto p : eyes)
            p->rotate(angle);
        if (mouth) {
            mouth->rotate(angle);
        }
    }
    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s) { mouth = s; }
    void wink(int i); // wink eye number i

private:
    vector<Shape*> eyes; // usually two eyes
    Shape* mouth;
};

void Smiley::wink(int i)
{
    if (i < eyes.size())
    {
        cout << "Winking eye " << i << endl;
    }
}

int main(int argc, char* argv[])
{
    try
    {
        example();
        Vector v(2);
        Vector vc = {2.345, 5.678};
        vc[0] = .345;
        v[1] = 5.789;
        try
        {
            v[8] = 7; // This will cause an out_of_range exception
        }
        catch (out_of_range& e)
        {
            cout << e.what() << '\n';
        }

        // Demonstrate Shape hierarchy
        Point p1{0, 0};
        Circle c1(p1, 5);
        c1.draw();

        Smiley s1(p1, 10);
        Point p2{10, 10};
        Circle* eye1 = new Circle(p2, 1);
        s1.add_eye(eye1);
        Point p3{20, 10};
        Circle* eye2 = new Circle(p3, 1);
        s1.add_eye(eye2);

        Point p4{15, 20};
        Circle* mouth = new Circle(p4, 3);
        s1.set_mouth(mouth);

        s1.draw();
        s1.wink(0);
        s1.wink(1);
        s1.move(Point{30, 30});
        s1.draw();
    }
    catch (length_error& e)
    {
        cout << e.what() << '\n';
    }
    catch (bad_alloc& e)
    {
        cout << e.what() << '\n';
    }
}
