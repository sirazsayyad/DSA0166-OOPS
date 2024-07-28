#include <iostream>
#include <string>
using namespace std;

class Customer {
protected:
    string name;
    int accountNumber;
    string accountType;
    double balance;
public:
    void setCustomerDetails(string n, int accNum, string accType) {
        name = n;
        accountNumber = accNum;
        accountType = accType;
        balance = 30.0;
    }

    void displayCustomerDetails() {
        cout << "Customer Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance() {
        return balance;
    }
};

class Savings {
public:
    void deposit(double amount, double &balance) {
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
    }

    void withdraw(double amount, double &balance) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
            cout << "Balance Amount After Withdraw: " << balance << endl;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }
};

class Current {
};

class Bank : public Customer, public Savings {
public:
    void deposit(double amount) {
        Savings::deposit(amount, balance);
    }

    void withdraw(double amount) {
        Savings::withdraw(amount, balance);
    }

    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Bank bank;
    char accountType;
    string name;
    int accountNumber;
    int choice;
    double amount;

    cout << "Enter S for saving customer and C for current a/c customer : ";
    cin >> accountType;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    if (accountType == 'S' || accountType == 's') {
        bank.setCustomerDetails(name, accountNumber, "Saving");
    } else if (accountType == 'C' || accountType == 'c') {
        bank.setCustomerDetails(name, accountNumber, "Current");
    } else {
        cout << "Invalid Account Type" << endl;
        return 0;
    }

    while (true) {
        cout << "\nChoose Your Choice\n";
        cout << "1) Deposit\n";
        cout << "2) Withdraw\n";
        cout << "3) Display Balance\n";
        cout << "4) Display with Full Details\n";
        cout << "5) Exit\n";
        cout << "Enter Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to Deposit: ";
            cin >> amount;
            bank.deposit(amount);
            break;
        case 2:
            cout << "Balance: " << bank.getBalance() << endl;
            cout << "Enter amount to Withdraw: ";
            cin >> amount;
            bank.withdraw(amount);
            break;
        case 3:
            bank.displayBalance();
            break;
        case 4:
            bank.displayCustomerDetails();
            break;
        case 5:
            cout << "Thank You for Banking with us.." << endl;
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
