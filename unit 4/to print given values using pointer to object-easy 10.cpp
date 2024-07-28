o#include <iostream>
using namespace std;

class ValuePrinter {
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
    ValuePrinter obj;
    ValuePrinter* ptr = &obj;

    ptr->setValue(42);
    ptr->printValue();

    return 0;
}
