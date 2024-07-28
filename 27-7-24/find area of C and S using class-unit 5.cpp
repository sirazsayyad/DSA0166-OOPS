#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0; // Pure virtual function
};

class Square : public Shape {
private:
    double length;
public:
    Square(double l) : length(l) {}
    double area() override {
        return length * length;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
};

int main() {
    double radius, length;
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Enter the length of the square: ";
    cin >> length;

    Circle circle(radius);
    Square square(length);

    cout << "Area of square: " << square.area() << endl;
    cout << "Area of circle: " << circle.area() << endl;

    return 0;
}
