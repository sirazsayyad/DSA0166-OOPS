#include <iostream>
using namespace std;

class Data {
private:
    int value;
public:
    void setValue(int v) {
        value = v;
    }

    void printValue() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Data obj;
    Data *ptr = &obj;

    int input;
    cout << "Enter a value: ";
    cin >> input;

    ptr->setValue(input);
    ptr->printValue();

    return 0;
}
