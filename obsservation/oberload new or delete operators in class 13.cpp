#include <iostream>
#include <cstdlib>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int val = 0) : value(val) {
        cout << "Constructor called for object with value " << value << endl;
    }

    ~MyClass() {
        cout << "Destructor called for object with value " << value << endl;
    }
    void* operator new(size_t size) {
        cout << "Overloaded new operator called. Size: " << size << endl;
        void* ptr = malloc(size);
        if (!ptr) {
            throw bad_alloc();
        }
        return ptr;
    }
    void operator delete(void* ptr) {
        cout << "Overloaded delete operator called." << endl;
        free(ptr);
    }
    void* operator new[](size_t size) {
        cout << "Overloaded new[] operator called. Size: " << size << endl;
        void* ptr = malloc(size);
        if (!ptr) {
            throw bad_alloc();
        }
        return ptr;
    }
    void operator delete[](void* ptr) {
        cout << "Overloaded delete[] operator called." << endl;
        free(ptr);
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};
int main() {
    MyClass* obj = new MyClass(10);
    obj->display();
    delete obj;
    MyClass* arr = new MyClass[3] { MyClass(1), MyClass(2), MyClass(3) };
    for (int i = 0; i < 3; ++i) {
        arr[i].display();
    }
    delete[] arr;

    return 0;
}
