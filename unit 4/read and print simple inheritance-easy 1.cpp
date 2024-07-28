#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    void getDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int studentID;
    void getStudentDetails() {
        getDetails();
        cout << "Enter student ID: ";
        cin >> studentID;
    }
    void displayStudentDetails() {
        displayDetails();
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student s;
    s.getStudentDetails();
    s.displayStudentDetails();
    return 0;
}
