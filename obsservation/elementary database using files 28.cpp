#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // For std::remove_if

using namespace std;

const string EMPLOYEE_FILE = "employees.txt";

struct Employee {
    int id;
    string name;
    string position;
    float salary;
};

vector<Employee> readEmployees() {
    vector<Employee> employees;
    ifstream file(EMPLOYEE_FILE);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Employee emp;
            ss >> emp.id;
            ss.ignore(); // Ignore the comma
            getline(ss, emp.name, ',');
            getline(ss, emp.position, ',');
            ss >> emp.salary;
            employees.push_back(emp);
        }
        file.close();
    }
    return employees;
}

void writeEmployees(const vector<Employee>& employees) {
    ofstream file(EMPLOYEE_FILE);
    if (file.is_open()) {
        for (const auto& emp : employees) {
            file << emp.id << "," << emp.name << "," << emp.position << "," << emp.salary << endl;
        }
        file.close();
    }
}

void addEmployee() {
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cin.ignore(); // Ignore the newline character after id
    cout << "Enter employee name: ";
    getline(cin, emp.name);
    cout << "Enter employee position: ";
    getline(cin, emp.position);
    cout << "Enter employee salary: ";
    cin >> emp.salary;

    vector<Employee> employees = readEmployees();
    employees.push_back(emp);
    writeEmployees(employees);
    cout << "Employee added successfully!" << endl;
}

void viewEmployees() {
    vector<Employee> employees = readEmployees();
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Position: " << emp.position << ", Salary: " << emp.salary << endl;
    }
}

void updateEmployee() {
    int id;
    cout << "Enter employee ID to update: ";
    cin >> id;
    cin.ignore(); // Ignore the newline character after id

    vector<Employee> employees = readEmployees();
    bool found = false;
    for (auto& emp : employees) {
        if (emp.id == id) {
            cout << "Enter new employee name: ";
            getline(cin, emp.name);
            cout << "Enter new employee position: ";
            getline(cin, emp.position);
            cout << "Enter new employee salary: ";
            cin >> emp.salary;
            found = true;
            break;
        }
    }

    if (found) {
        writeEmployees(employees);
        cout << "Employee updated successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

void deleteEmployee() {
    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    vector<Employee> employees = readEmployees();
    auto it = remove_if(employees.begin(), employees.end(), [id](const Employee& emp) { return emp.id == id; });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        writeEmployees(employees);
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

void menu() {
    int choice;
    do {
        cout << "\nEmployee Database Menu\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character after choice

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
