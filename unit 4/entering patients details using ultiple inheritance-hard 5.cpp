#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
    string address;
public:
    void setPersonalDetails(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }
    void displayPersonalDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};
class Patient : public Person {
private:
    string patientID;
    string medicalHistory;
public:
   
    void setPatientDetails(string id, string history) {
        patientID = id;
        medicalHistory = history;
    }

    // Function to display patient details
    void displayPatientDetails() const {
        displayPersonalDetails(); // Call base class function
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }
};

int main() {
    Patient patient;

    string name;
    int age;
    string address;
    string patientID;
    string medicalHistory;
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(); 
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Patient ID: ";
    getline(cin, patientID);
    cout << "Enter Medical History: ";
    getline(cin, medicalHistory);
    patient.setPersonalDetails(name, age, address);
    patient.setPatientDetails(patientID, medicalHistory);
    cout << "\nPatient Details:" << endl;
    patient.displayPatientDetails();

    return 0;
}
