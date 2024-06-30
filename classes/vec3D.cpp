#include <iostream>
#include <functional>

class Vector3D {
private:
    double x, y, z;

public:
    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    // Overload the + operator
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Overload the - operator
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Overload the * operator (dot product)
    double operator*(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Overload the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
        os << "Vector3D(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }
};

int main() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);

    Vector3D v3 = v1 + v2;
    Vector3D v4 = v1 - v2;
    double dotProduct = v1 * v2;

    std::cout << "v1 + v2 = " << v3 << std::endl;
    std::cout << "v1 - v2 = " << v4 << std::endl;
    std::cout << "v1 * v2 (dot product) = " << dotProduct << std::endl;

    return 0;
}
