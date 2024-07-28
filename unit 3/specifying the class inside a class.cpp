#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor declaration inside the class
    Rectangle(double l, double w);

    void displayArea();
};

// Constructor definition outside the class
Rectangle::Rectangle(double l, double w) : length(l), width(w) {
    // Constructor body (initialization list is used to initialize members)
    cout << "Rectangle created with length " << length << " and width " << width << endl;
}

// Member function definition
void Rectangle::displayArea() {
    double area = length * width;
    cout << "Area of Rectangle: " << area << endl;
}

int main() {
    double length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Creating an object of Rectangle class using the constructor
    Rectangle rect(length, width);

    // Displaying the area of the rectangle
    rect.displayArea();

    return 0;
}
