#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
    string name;
    int rollNumber;
    float marks;

public:
    void setDetails(string n, int roll, float m) {
        name = n;
        rollNumber = roll;
        marks = m;
    }
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

// Derived class
class Report : public Student {
public:
    void generateReport() {
        cout << "Student Report:" << endl;
        displayDetails();
        cout << "Report Generated Successfully!" << endl;
    }
};

int main() {
    Report studentReport;

    string name;
    int rollNumber;
    float marks;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Marks: ";
    cin >> marks;
    studentReport.setDetails(name, rollNumber, marks);
    studentReport.generateReport();

    return 0;
}
