#include <iostream>
#include <cmath>
using namespace std;

class AreaCalculator {
private:
    double radius;
    double length;  
    double width; 
    double base;  
    double height;  

public:
    AreaCalculator(double r = 0, double l = 0, double w = 0, double b = 0, double h = 0)
        : radius(r), length(l), width(w), base(b), height(h) {
        if (radius > 0) {
            calculateCircleArea();
        } else if (length > 0 && width > 0) {
            calculateRectangleArea();
        } else if (base > 0 && height > 0) {
            calculateTriangleArea();
        } else {
            cout << "No valid dimensions provided." << endl;
        }
    }

    void calculateCircleArea() {
        double area = M_PI * radius * radius;
        cout << "Area of Circle with radius " << radius << " is: " << area << endl;
    }

    void calculateRectangleArea() {
        double area = length * width;
        cout << "Area of Rectangle with length " << length << " and width " << width << " is: " << area << endl;
    }

    void calculateTriangleArea() {
        double area = 0.5 * base * height;
        cout << "Area of Triangle with base " << base << " and height " << height << " is: " << area << endl;
    }
};

int main() {
    int choice;
    cout << "Choose the shape to calculate the area:\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cin >> choice;

    if (choice == 1) {
        double radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        AreaCalculator circle(radius); 
    } else if (choice == 2) {
        double length, width;
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        AreaCalculator rectangle(0, length, width);
    } else if (choice == 3) {
        double base, height;
        cout << "Enter the base and height of the triangle: ";
        cin >> base >> height;
        AreaCalculator triangle(0, 0, 0, base, height); 
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
