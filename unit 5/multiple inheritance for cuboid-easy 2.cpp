#include <iostream>
using namespace std;

class Shape {
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
};

class Rectangle : public Shape {
protected:
    double length;
    double breadth;
public:
    void getData() override {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }
    void displayData() override {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
    }
    double area() {
        return length * breadth;
    }
};

class Cuboid : public Rectangle {
protected:
    double height;
public:
    void getData() override {
        Rectangle::getData();
        cout << "Enter height: ";
        cin >> height;
    }
    void displayData() override {
        Rectangle::displayData();
        cout << "Height: " << height << endl;
    }
    double volume() {
        return area() * height;
    }
};

int main() {
    Cuboid cuboid;
    cuboid.getData();
    cuboid.displayData();
    cout << "Area: " << cuboid.area() << endl;
    cout << "Volume: " << cuboid.volume() << endl;
    return 0;
}
