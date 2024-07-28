#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    virtual void displayData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    virtual double bonus() = 0;
};

class Admin : virtual public Person {
protected:
    double adminBonus;
public:
    void getData() override {
        Person::getData();
        cout << "Enter admin bonus: ";
        cin >> adminBonus;
    }
    void displayData() override {
        Person::displayData();
        cout << "Admin Bonus: " << adminBonus << endl;
    }
    double bonus() override {
        return adminBonus;
    }
};

class Account : virtual public Person {
protected:
    double accountBonus;
public:
    void getData() override {
        Person::getData();
        cout << "Enter account bonus: ";
        cin >> accountBonus;
    }
    void displayData() override {
        Person::displayData();
        cout << "Account Bonus: " << accountBonus << endl;
    }
    double bonus() override {
        return accountBonus;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData();
        Account::getData();
    }
    void displayData() override {
        Admin::displayData();
        Account::displayData();
    }
    double bonus() override {
        return Admin::bonus() + Account::bonus();
    }
};

int main() {
    Master master;
    master.getData();
    master.displayData();
    cout << "Total Bonus: " << master.bonus() << endl;
    return 0;
}
