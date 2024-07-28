#include <iostream>
using namespace std;

class A {
protected:
    int x;
public:
    void getX() {
        cout << "Enter value of x: ";
        cin >> x;
    }
};

class B {
protected:
    int y;
public:
    void getY() {
        cout << "Enter value of y: ";
        cin >> y;
    }
};

class C : public A, public B {
public:
    void displaySum() {
        cout << "Sum = " << x + y << endl;
    }
};

int main() {
    C obj;
    obj.getX();
    obj.getY();
    obj.displaySum();
    return 0;
}
