#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual double bonus() = 0;
};

class Admin : virtual public Person {
protected:
    double adminBonus;
public:
    void getData() override {
        cout << "Enter admin name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter admin bonus: ";
        cin >> adminBonus;
    }
    void displayData() override {
        cout << "Admin Name: " << name << endl;
        cout << "Age: " << age << endl;
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
        cout << "Enter account name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter account bonus: ";
        cin >> accountBonus;
    }
    void displayData() override {
        cout << "Account Name: " << name << endl;
        cout << "Age: " << age << endl;
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
    Person *p;
    Master master;
    p = &master;
    
    p->getData();
    p->displayData();
    cout << "Total Bonus: " << p->bonus() << endl;
    
    return 0;
}
