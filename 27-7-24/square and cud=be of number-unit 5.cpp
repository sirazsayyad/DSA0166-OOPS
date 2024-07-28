#include <iostream>
using namespace std;

class Number {
protected:
    int num;
public:
    void getNumber() {
        cout << "Enter an integer number: ";
        cin >> num;
    }
};

class Square : public Number {
public:
    void displaySquare() {
        cout << "Square of " << num << " is: " << num * num << endl;
    }
};

class Cube : public Number {
public:
    void displayCube() {
        cout << "Cube of " << num << " is: " << num * num * num << endl;
    }
};

int main() {
    Square sq;
    Cube cu;

    sq.getNumber();
    sq.displaySquare();

    cu.getNumber();
    cu.displayCube();

    return 0;
}
