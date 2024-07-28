#include <iostream>
using namespace std;

class Grandfather {
protected:
    double propertyValue;
public:
    Grandfather() : propertyValue(500) {} // Assume 500 Cr property
    virtual void displayProperty() {
        cout << "Grandfather's property: " << propertyValue << " Cr" << endl;
    }
};

class Father : public Grandfather {
public:
    void displayProperty() override {
        cout << "Father's property: " << propertyValue << " Cr" << endl;
    }
};

class Grandson : public Father {
public:
    void displayProperty() override {
        cout << "Grandson's property: " << propertyValue << " Cr" << endl;
    }
};

int main() {
    Grandson grandson;
    grandson.displayProperty();
    return 0;
}
