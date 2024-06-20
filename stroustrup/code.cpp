// C++ program to demonstrate working
// of Enum Classes

#include <iostream>
using namespace std;

int main()
{
    typedef enum {a, b, c} A; 
	enum class Color { Red = 2,
					Green,
					Blue };
	enum class Color2 { Red,
						Black,
						White };
	int Green = 10;

	Color x = Color::Green;

	if (x == Color::Red)
		cout << "It's Red\n";
	else
		cout << "It's not Red\n";

	cout << int(x);

	return 0;
}
