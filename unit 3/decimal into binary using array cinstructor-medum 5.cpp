#include <iostream>
using namespace std;

class DecimalToBinary {
private:
    int decimalNumber;
    void convertToBinary() {
        int number = decimalNumber;
        string binary = "";
        
        if (number == 0) {
            binary = "0";
        } else {
            while (number > 0) {
                binary = to_string(number % 2) + binary;
                number /= 2;
            }
        }
        
        cout << "Binary representation of " << decimalNumber << " is: " << binary << endl;
    }

public:
    DecimalToBinary() : decimalNumber(0) {
        cout << "No decimal number provided." << endl;
    }
    DecimalToBinary(int decimal) : decimalNumber(decimal) {
        convertToBinary();
    }
    DecimalToBinary(int start, bool) {
        for (int i = start; i <= start + 5; ++i) {
            decimalNumber = i;
            convertToBinary();
        }
    }
};

int main() {
    int choice;
    cout << "Choose the option:\n";
    cout << "1. Convert a single decimal number to binary\n";
    cout << "2. Convert a range of decimal numbers to binary\n";
    cin >> choice;

    if (choice == 1) {
        int decimal;
        cout << "Enter the decimal number: ";
        cin >> decimal;
        DecimalToBinary singleConversion(decimal);  
    } else if (choice == 2) {
        int start;
        cout << "Enter the starting decimal number: ";
        cin >> start;
        DecimalToBinary rangeConversion(start, true);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
