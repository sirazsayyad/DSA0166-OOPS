#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Employee : public Person {
protected:
    int employeeID;
public:
    void setEmployeeDetails(int id) {
        employeeID = id;
    }

    void displayEmployeeDetails() {
        displayPersonDetails();
        cout << "Employee ID: " << employeeID << endl;
    }
};
class Salary {
protected:
    double basicSalary;
    double allowances;
public:
    void setSalaryDetails(double basic, double allow) {
        basicSalary = basic;
        allowances = allow;
    }

    double calculateTotalSalary() {
        return basicSalary + allowances;
    }

    void displaySalaryDetails() {
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Allowances: $" << allowances << endl;
        cout << "Total Salary: $" << calculateTotalSalary() << endl;
    }
};
class FullTimeEmployee : public Employee, public Salary {
public:
    void displayFullTimeEmployeeDetails() {
        displayEmployeeDetails();
        displaySalaryDetails();
    }
};

int main() {
    FullTimeEmployee emp;

    string name;
    int age, employeeID;
    double basicSalary, allowances;
    cout << "Enter Name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cout << "Enter Basic Salary: ";
    cin >> basicSalary;
    cout << "Enter Allowances: ";
    cin >> allowances;
    emp.setPersonDetails(name, age);
    emp.setEmployeeDetails(employeeID);
    emp.setSalaryDetails(basicSalary, allowances);
    emp.displayFullTimeEmployeeDetails();

    return 0;
}
