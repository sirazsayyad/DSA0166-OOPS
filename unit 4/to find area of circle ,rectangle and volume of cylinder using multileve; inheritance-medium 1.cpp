#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;
    double length;
    double width;
public:
    void setCircleDimensions(double r) {
        radius = r;
    }

    void setRectangleDimensions(double l, double w) {
        length = l;
        width = w;
    }
};

class Circle : public Shape {
public:
    double getAreaCircle() {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
public:
    double getAreaRectangle() {
        return length * width;
    }
};

class Cylinder : public Circle {
private:
    double height;
public:
    void setHeight(double h) {
        height = h;
    }

    double getVolumeCylinder() {
        return M_PI * radius * radius * height;
    }
};

int main() {
    Circle circle;
    circle.setCircleDimensions(5.0);
    cout << "Area of Circle: " << circle.getAreaCircle() << endl;

    Rectangle rectangle;
    rectangle.setRectangleDimensions(6.0, 4.0);
    cout << "Area of Rectangle: " << rectangle.getAreaRectangle() << endl;

    Cylinder cylinder;
    cylinder.setCircleDimensions(5.0);
    cylinder.setHeight(10.0);
    cout << "Volume of Cylinder: " << cylinder.getVolumeCylinder() << endl;

    return 0;
}
