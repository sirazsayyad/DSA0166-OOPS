#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;
public:
    void setDetails(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }

    void displayDetails() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
};

int main() {
    const int size = 3;
    Employee employees[size];

    employees[0].setDetails("Alice", 101, 50000);
    employees[1].setDetails("Bob", 102, 55000);
    employees[2].setDetails("Charlie", 103, 60000);

    for (int i = 0; i < size; i++) {
        employees[i].displayDetails();
    }

    return 0;
}
