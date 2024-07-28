#include <iostream>
using namespace std;

class Employee {
protected:
    string emp_name;
    int emp_id;
    double basic_salary;
public:
    Employee(string name, int id, double salary)
        : emp_name(name), emp_id(id), basic_salary(salary) {}
    virtual void calculatePay() = 0;
    void display() {
        cout << "Employee Name: " << emp_name << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Basic Salary: $" << basic_salary << endl;
    }
};

class Pay : public Employee {
private:
    double gross_pay;
    double net_pay;
public:
    Pay(string name, int id, double salary)
        : Employee(name, id, salary), gross_pay(0), net_pay(0) {}

    void calculatePay() override {
        double hra = basic_salary * 0.10;
        double da = basic_salary * 0.05;
        double pf = basic_salary * 0.12;
        gross_pay = basic_salary + hra + da;
        net_pay = gross_pay - pf;
    }

    void display() {
        Employee::display();
        cout << "Gross Pay: $" << gross_pay << endl;
        cout << "Net Pay: $" << net_pay << endl;
    }
};

int main() {
    Pay emp("John Doe", 12345, 5000);
    emp.calculatePay();
    emp.display();
    
    return 0;
}
