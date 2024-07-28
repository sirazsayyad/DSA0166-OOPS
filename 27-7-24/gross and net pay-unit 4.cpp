#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string emp_id;
    double basic_salary;
public:
    Employee(string n, string id, double salary) : name(n), emp_id(id), basic_salary(salary) {}
    virtual void display() {
        cout << "Enter employee name: " << name << endl;
        cout << "Enter Employee id: " << emp_id << endl;
        cout << "Enter Employee Salary: " << basic_salary << endl;
    }
};

class Salary : public Employee {
public:
    Salary(string n, string id, double salary) : Employee(n, id, salary) {}
    double gross_salary() {
        return basic_salary + (basic_salary * 0.70); // 70% as allowances
    }
    double net_salary() {
        return gross_salary() - (basic_salary * 0.50); // 50% as deductions
    }
    void display() override {
        Employee::display();
        cout << "Gross salary: " << gross_salary() << endl;
        cout << "Deduction: " << basic_salary * 0.50 << endl;
        cout << "Net salary = " << net_salary() << endl;
    }
};

int main() {
    string name = "Mohan";
    string emp_id = "A101";
    double basic_salary = 100000;
    Salary emp(name, emp_id, basic_salary);
    emp.display();
    return 0;
}
