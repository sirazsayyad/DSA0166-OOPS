#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    Square square(5.0);
    Circle circle(3.0);

    std::cout << "Area of square: " << square.area() << std::endl;
    std::cout << "Area of circle: " << circle.area() << std::endl;

    return 0;
}
