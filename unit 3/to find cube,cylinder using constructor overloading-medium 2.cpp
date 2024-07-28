#include <iostream>
#include <cmath>
using namespace std;

class VolumeCalculator {
private:
    double side;      
    double radius;    
    double height;    

public:
    VolumeCalculator() : side(0), radius(0), height(0) {
        cout << "No dimensions provided." << endl;
    }
    VolumeCalculator(double s) : side(s), radius(0), height(0) {
        calculateCubeVolume();
    }
    VolumeCalculator(double r, double h) : side(0), radius(r), height(h) {
        calculateCylinderVolume();
    }

    void calculateCubeVolume() {
        double volume = pow(side, 3);
        cout << "Volume of Cube with side length " << side << " is: " << volume << endl;
    }

    void calculateCylinderVolume() {
        double volume = M_PI * pow(radius, 2) * height;
        cout << "Volume of Cylinder with radius " << radius << " and height " << height << " is: " << volume << endl;
    }
};

int main() {
    int choice;
    cout << "Choose the shape to calculate the volume:\n";
    cout << "1. Cube\n";
    cout << "2. Cylinder\n";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Enter the side length of the cube: ";
        cin >> side;
        VolumeCalculator cube(side); 
    } else if (choice == 2) {
        double radius, height;
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> height;
        VolumeCalculator cylinder(radius, height); 
    } else {
        cout << "Invalid choice! Please select either 1 or 2." << endl;
    }

    return 0;
}
