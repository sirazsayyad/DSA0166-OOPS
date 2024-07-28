#include <iostream>
using namespace std;

class Pattern {
public:
    Pattern() {
        // Default constructor
        cout << "No pattern to display." << endl;
    }

    Pattern(int n) {
        // Constructor to print the pattern
        printPattern(n);
    }

    void printPattern(int n) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;

    cout << "Enter the number of rows: ";
    cin >> n;

    if (n > 0) {
        Pattern pattern(n);  // Using the parameterized constructor
    } else {
        Pattern defaultPattern;  // Using the default constructor
    }

    return 0;
}