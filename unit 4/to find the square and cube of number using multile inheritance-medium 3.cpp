#include <iostream>
using namespace std;

class Number {
protected:
    int num;
public:
    void setNumber(int n) {
        num = n;
    }
};

class Square : public Number {
public:
    int getSquare() {
        return num * num;
    }
};

class Cube : public Number {
public:
    int getCube() {
        return num * num * num;
    }
};

int main() {
    Square sq;
    Cube cu;

    sq.setNumber(3);
    cu.setNumber(3);

    cout << "Square of 3: " << sq.getSquare() << endl;
    cout << "Cube of 3: " << cu.getCube() << endl;

    return 0;
}
