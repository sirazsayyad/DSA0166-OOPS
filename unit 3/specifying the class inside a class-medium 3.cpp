#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);

    void displayArea();
};
Rectangle::Rectangle(double l, double w) : length(l), width(w) {
    cout << "Rectangle created with length " << length << " and width " << width << endl;
}
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
    Rectangle rect(length, width);
    rect.displayArea();

    return 0;
}
