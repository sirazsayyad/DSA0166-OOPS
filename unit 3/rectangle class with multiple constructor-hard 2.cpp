#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(double l, double b) : length(l), breadth(b) {}
    Rectangle(double side) : length(side), breadth(side) {}
    double calculateArea() const {
        return length * breadth;
    }
};

int main() {
    Rectangle rect1;                 
    Rectangle rect2(5, 3);          
    Rectangle rect3(4);        
    cout << "Area of rect1: " << rect1.calculateArea() << endl;
    cout << "Area of rect2: " << rect2.calculateArea() << endl;
    cout << "Area of rect3: " << rect3.calculateArea() << endl;

    return 0;
}
