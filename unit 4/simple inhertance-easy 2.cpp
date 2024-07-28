#include <iostream>
using namespace std;

class Base {
private:
    int a;
public:
    void setA(int val) { a = val; }
    int getA() { return a; }
};

class Derived : private Base {
public:
    void setBaseA(int val) { setA(val); }
    int getBaseA() { return getA(); }
};

int main() {
    Derived d;
    d.setBaseA(10);
    cout << "Value in base class (through derived): " << d.getBaseA() << endl;
    return 0;
}
