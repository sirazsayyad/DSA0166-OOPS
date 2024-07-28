#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }
};

int main() {
    const int size = 3;
    Rectangle rectangles[size];

    rectangles[0].setDimensions(5.0, 3.0);
    rectangles[1].setDimensions(6.0, 4.0);
    rectangles[2].setDimensions(7.0, 5.0);

    for (int i = 0; i < size; i++) {
        cout << "Area of rectangle " << i + 1 << ": " << rectangles[i].getArea() << endl;
    }

    return 0;
}
