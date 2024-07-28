#include <iostream>
using namespace std;

class Base1 {
protected:
    int num1;
public:
    void setNum1(int n) {
        num1 = n;
    }
};

class Base2 {
protected:
    int num2;
public:
    void setNum2(int n) {
        num2 = n;
    }
};

class Derived : public Base1, public Base2 {
public:
    int getSum() {
        return num1 + num2;
    }
};

int main() {
    Derived obj;
    obj.setNum1(5);
    obj.setNum2(10);
    cout << "Sum: " << obj.getSum() << endl;
    return 0;
}
