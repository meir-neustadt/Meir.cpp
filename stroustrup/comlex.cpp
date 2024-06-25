#include <iostream>
#include <cmath> // For sqrt and atan2

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // Getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setters
    void setReal(double real) { this->real = real; }
    void setImag(double imag) { this->imag = imag; }

    // Addition of two complex numbers
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction of two complex numbers
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Subtraction of a complex numbers
    Complex operator-() const
    {
        return Complex(-real, -imag);
    }

    // Multiplication of two complex numbers
    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Division of two complex numbers
    Complex operator/(const Complex &other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Magnitude of the complex number
    double magnitude() const
    {
        return std::sqrt(real * real + imag * imag);
    }

    // Phase (argument) of the complex number
    double phase() const
    {
        return std::atan2(imag, real);
    }

    // Print the complex number
    void print() const
    {
        std::cout << "(" << real << ", " << imag << "i)\n";
    }
};

class binInt {
private:
    int num;

public:
    // Constructor to initialize the number
    binInt(int n = 0) : num(n) {}

    // Pre-decrement operator to decrement by 2
    binInt& operator--() {
        num -= 2;
        return *this;
    }

    // Post-decrement operator to decrement by 2
    binInt operator--(int) {
        binInt temp = *this; // Create a copy of the current object
        num -= 2;
        return temp; // Return the copy (the original value before decrement)
    }

    // Function to display the value
    void display() const {
        std::cout << num << std::endl;
    }
};


int main()
{
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;
    Complex minus = -c1;

    std::cout << "c1: ";
    c1.print(); // Output: (3, 4i)
    std::cout << "c2: ";
    c2.print(); // Output: (1, 2i)

    std::cout << "Sum: ";
    sum.print(); // Output: (4, 6i)
    std::cout << "Difference: ";
    difference.print(); // Output: (2, 2i)
    std::cout << "Product: ";
    product.print(); // Output: (-5, 10i)
    std::cout << "Quotient: ";
    quotient.print(); // Output: (2.2, 0.4i)
    std::cout << "Minus: ";
    quotient.print(); // Output: (2.2, 0.4i)

    std::cout << "Magnitude of c1: " << c1.magnitude() << '\n'; // Output: 5
    std::cout << "Phase of c1: " << c1.phase() << " radians\n"; // Output: 0.927295 radians
    std::cout << minus.magnitude();


    binInt b(10);

    std::cout << "Initial value: ";
    b.display();

    b--;

    std::cout << "After pre-decrement: ";
    b.display();

    return 0;
}
