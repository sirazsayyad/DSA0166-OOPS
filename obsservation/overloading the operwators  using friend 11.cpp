#include <iostream>
using namespace std;

class Vector {
private:
    int x, y, z;

public:
    Vector() : x(0), y(0), z(0) {}
    Vector(int x, int y, int z) : x(x), y(y), z(z) {}
    friend Vector operator*(const Vector& v, int scalar);
    friend Vector operator*(int scalar, const Vector& v);
    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};
Vector operator*(const Vector& v, int scalar) {
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar);
}
Vector operator*(int scalar, const Vector& v) {
    return v * scalar; 
}
ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}
istream& operator>>(istream& in, Vector& v) {
    cout << "Enter x, y, z: ";
    in >> v.x >> v.y >> v.z;
    return in;
}
int main() {
    Vector v1, v2;
    int scalar;
    cout << "Enter vector v1: " << endl;
    cin >> v1;
    cout << "Enter scalar: ";
    cin >> scalar;
    v2 = v1 * scalar;
    cout << "v1 * scalar: " << v2 << endl;
    v2 = scalar * v1;
    cout << "scalar * v1: " << v2 << endl;
    return 0;
}
