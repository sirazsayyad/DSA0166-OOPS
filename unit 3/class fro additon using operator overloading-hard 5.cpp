#include <iostream>
using namespace std;

class Add {
private:
    int value;

public:
    Add(int v = 0) : value(v) {}
    Add operator+(const Add& other) const {
        return Add(value + other.value);
    }
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Add a1(num1), a2(num2);
    Add result = a1 + a2;
    result.display();

    return 0;
}
