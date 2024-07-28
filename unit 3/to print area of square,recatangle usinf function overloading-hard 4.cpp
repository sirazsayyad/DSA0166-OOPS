#include <iostream>
using namespace std;

class Shape {
public:
    void printArea(double side) {
        double area = side * side;
        cout << "Area of the square with side " << side << " is: " << area << endl;
    }
    void printArea(double length, double breadth) {
        double area = length * breadth;
        cout << "Area of the rectangle with length " << length << " and breadth " << breadth << " is: " << area << endl;
    }
};

int main() {
    Shape shape;

    double side, length, breadth;

    cout << "Enter the side of the square: ";
    cin >> side;
    shape.printArea(side);  

    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;
    shape.printArea(length, breadth); 
    return 0;
}
