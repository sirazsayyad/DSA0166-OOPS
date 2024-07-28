#include <iostream>
using namespace std;

class Shape {
public:
    virtual void display() = 0; // Pure virtual function for polymorphism
};

class Rectangle : public Shape {
protected:
    double length;
    double breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() {
        return length * breadth;
    }
    void display() override {
        cout << "AREA OF RECTANGLE = " << area() << endl;
    }
};

class Cuboid : public Rectangle {
private:
    double height;
public:
    Cuboid(double l, double b, double h) : Rectangle(l, b), height(h) {}
    double volume() {
        return length * breadth * height;
    }
    void display() override {
        Rectangle::display();
        cout << "VOLUME OF RECTANGLE = " << volume() << endl;
    }
};

int main() {
    double length = 10, breadth = 10, height = 10;
    Cuboid cuboid(length, breadth, height);
    cuboid.display();
    return 0;
}
