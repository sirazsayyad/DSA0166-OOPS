#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;

public:
    Student() : name("Unknown") {
        cout << "Student name: " << name << endl;
    }
    Student(const string& studentName) : name(studentName) {
        cout << "Student name: " << name << endl;
    }
};

int main() {
    Student student1;             
    Student student2("John Doe");  

    return 0;
}
