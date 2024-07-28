#include <iostream>
using namespace std;

class MyClass {
private:
    int* data;

public:
    MyClass(int value) {
        data = new int;
        *data = value;
        cout << "Constructor called. Value: " << *data << endl;
    }
    MyClass(const MyClass& other) {
        data = new int;
        *data = *(other.data);
        cout << "Copy Constructor called. Value: " << *data << endl;
    }
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this;
        }
        *data = *(other.data);
        cout << "Assignment Operator called. Value: " << *data << endl;
        return *this;
    }
    ~MyClass() {
        delete data;
        cout << "Destructor called." << endl;
    }

    void display() const {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; 
    MyClass obj3(20);
    obj3 = obj1; 

    return 0;
}
