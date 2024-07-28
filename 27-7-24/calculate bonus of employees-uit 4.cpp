#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int emp_id;
public:
    virtual void getdata() = 0;
    virtual void displaydata() = 0;
    virtual double bonus() = 0;
};

class Admin : virtual public Person {
protected:
    double salary;
public:
    void getdata() override {
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displaydata() override {
        cout << "Salary: " << salary << endl;
    }
    double bonus() override {
        return salary + 1000;
    }
};

class Account : virtual public Person {
protected:
    double salary;
public:
    void getdata() override {
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displaydata() override {
        cout << "Salary: " << salary << endl;
    }
    double bonus() override {
        return salary + 1000;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
    }
    void displaydata() override {
        Admin::displaydata();
    }
    double bonus() override {
        return Admin::bonus();
    }
};

int main() {
    Master employee;
    employee.getdata();
    cout << "Bonus = " << employee.bonus() << endl;
    return 0;
}
