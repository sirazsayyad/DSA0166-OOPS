#include <iostream>
using namespace std;

class ReverseNumber {
public:
    int number;

    // Default constructor
    ReverseNumber() {
        cout << "No number provided." << endl;
    }

    // Parameterized constructor
    ReverseNumber(int n) : number(n) {
        displayReverse();
    }

    void displayReverse() {
        int reversedNumber = 0;
        int temp = number;

        while (temp != 0) {
            int digit = temp % 10;
            reversedNumber = reversedNumber * 10 + digit;
            temp /= 10;
        }

        cout << "Reverse of " << number << " is " << reversedNumber << endl;
    }
};

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n > 0) {
        ReverseNumber reverseNum(n);  // Using the parameterized constructor
    } else {
        ReverseNumber defaultReverse;  // Using the default constructor
    }

    return 0;
}
