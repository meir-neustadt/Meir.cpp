// C++ program to demonstrate working
// of Enum Classes

#include <iostream>
using namespace std;

enum class trafficLight
{
    green,
    yellow,
    red
} light;

trafficLight& operator++(trafficLight &t)
{
    switch (t)
    {
    case trafficLight::green:
        return t = trafficLight::yellow;
    case trafficLight::yellow:
        return t = trafficLight::red;
    case trafficLight::red:
        return t = trafficLight::green;
    }
};

int main()
{
    enum aaa
    {
        a,
        b,
        c
    } A;
    enum class Color
    {
        Red = 2,
        Green,
        Blue
    };
    enum class eyecolor : char
    {
        blue = 's',
        green,
        brown
    } Eye;

    Color x = Color::Green;

    if (x == Color::Red)
        cout << "It's Red\n";
    else
        cout << "It's not Red\n";

    trafficLight Light = trafficLight::yellow;
    trafficLight next = ++Light;

    cout << int(x) << endl;
    cout << char(eyecolor::green) << endl;
    cout << int(trafficLight::yellow) << endl << int(Light) << endl << int(next);

    return 0;
}
