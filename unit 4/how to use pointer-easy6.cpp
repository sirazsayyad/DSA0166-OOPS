#include <iostream>

class Example {
    int a;
public:
    Example(int a) {
        this->a = a;
    }
    void display() {
        std::cout << "Value of a: " << this->a << std::endl;
    }
};

int main() {
    Example ex(10);
    ex.display();
    return 0;
}
