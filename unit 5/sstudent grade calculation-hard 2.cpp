#include <iostream>
using namespace std;

class Student {
private:
    int marks[4];
    int total;
    float aggregate;
public:
    void getData() {
        total = 0;
        for (int i = 0; i < 4; ++i) {
            cout << "Enter marks for subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
        aggregate = total / 4.0;
    }

    void displayData() {
        cout << "Total marks: " << total << endl;
        cout << "Aggregate marks: " << aggregate << endl;
        try {
            if (aggregate < 50) {
                throw "fail";
            } else {
                cout << "Grade: Pass" << endl;
            }
        } catch (const char* msg) {
            cout << "Grade: " << msg << endl;
        }
    }
};

int main() {
    Student student;
    student.getData();
    student.displayData();
    return 0;
}
