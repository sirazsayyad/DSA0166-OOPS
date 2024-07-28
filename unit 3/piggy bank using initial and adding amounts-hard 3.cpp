#include <iostream>
using namespace std;

class AddAmount {
private:
    double amount;

public:
    AddAmount() : amount(50) {}
    AddAmount(double addAmount) : amount(50 + addAmount) {}
    void displayAmount() const {
        cout << "Final amount in the Piggie Bank: $" << amount << endl;
    }
};

int main() {
    double additionalAmount;

    cout << "Enter the amount to add to the Piggie Bank: ";
    cin >> additionalAmount;
    AddAmount piggieBank(additionalAmount);
    piggieBank.displayAmount();

    return 0;
}
