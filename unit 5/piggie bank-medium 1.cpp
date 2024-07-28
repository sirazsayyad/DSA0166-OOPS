#include <iostream>
using namespace std;

class AddAmount {
protected:
    double amount;
public:
    AddAmount() : amount(50) {} // Initial amount is $50
    virtual void addAmount() = 0;
    void displayAmount() {
        cout << "Total amount in Piggie Bank: $" << amount << endl;
    }
};

class NoAddAmount : public AddAmount {
public:
    void addAmount() override {
        // No amount added
    }
};

class AddSomeAmount : public AddAmount {
private:
    double additionalAmount;
public:
    AddSomeAmount(double addAmount) : additionalAmount(addAmount) {}
    void addAmount() override {
        amount += additionalAmount;
    }
};

int main() {
    AddAmount *piggie;
    
    NoAddAmount noAdd;
    piggie = &noAdd;
    piggie->addAmount();
    piggie->displayAmount();
    
    AddSomeAmount add(100);  // Adding $100
    piggie = &add;
    piggie->addAmount();
    piggie->displayAmount();
    
    return 0;
}
