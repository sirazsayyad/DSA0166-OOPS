#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class BinaryToOctal {
private:
    string binary;
    string octal;

    int binaryToDecimal(string binary) {
        int decimal = 0;
        int length = binary.length();
        for (int i = 0; i < length; ++i) {
            if (binary[length - i - 1] == '1') {
                decimal += pow(2, i);
            }
        }
        return decimal;
    }

    string decimalToOctal(int decimal) {
        string octal = "";
        while (decimal != 0) {
            octal = to_string(decimal % 8) + octal;
            decimal /= 8;
        }
        return octal.empty() ? "0" : octal;
    }

public:
    BinaryToOctal(string bin) : binary(bin) {
        int decimal = binaryToDecimal(binary);
        octal = decimalToOctal(decimal);
        displayResult();
    }

    void displayResult() {
        cout << "Binary: " << binary << " -> Octal: " << octal << endl;
    }
};

int main() {
    string binary;

    cout << "Enter a binary number: ";
    cin >> binary;

    BinaryToOctal converter(binary); 
    
    

    return 0;
}
