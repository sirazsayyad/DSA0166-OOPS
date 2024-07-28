#include <iostream>
using namespace std;

class IncomeTax {
protected:
    double income;
public:
    void getData() {
        cout << "Enter the income: ";
        cin >> income;
    }
    virtual double TDS() = 0;
};

class Slab1 : public IncomeTax {
public:
    double TDS() override {
        if (income <= 150000) {
            return 0;
        } else {
            return -1;  // Not in this slab
        }
    }
};

class Slab2 : public IncomeTax {
public:
    double TDS() override {
        if (income > 150000 && income <= 300000) {
            return (income - 150000) * 0.10;
        } else {
            return -1;  // Not in this slab
        }
    }
};

class Slab3 : public IncomeTax {
public:
    double TDS() override {
        if (income > 300000 && income <= 500000) {
            return (income - 300000) * 0.20 + 15000;
        } else if (income > 500000) {
            return (income - 500000) * 0.30 + 15000 + 40000;
        } else {
            return -1;  // Not in this slab
        }
    }
};

int main() {
    IncomeTax *tax;
    Slab1 s1;
    Slab2 s2;
    Slab3 s3;

    tax = &s1;
    tax->getData();
    double taxAmount = tax->TDS();
    if (taxAmount != -1) {
        cout << "Tax amount: " << taxAmount << endl;
        return 0;
    }

    tax = &s2;
    taxAmount = tax->TDS();
    if (taxAmount != -1) {
        cout << "Tax amount: " << taxAmount << endl;
        return 0;
    }

    tax = &s3;
    taxAmount = tax->TDS();
    if (taxAmount != -1) {
        cout << "Tax amount: " << taxAmount << endl;
        return 0;
    }

    cout << "Error in tax calculation" << endl;
    return 0;
}
