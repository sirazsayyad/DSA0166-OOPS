#include <iostream>
using namespace std;

class RightAngleTriangle {
public:
    // Default constructor
    RightAngleTriangle() {
        cout << "No size specified." << endl;
    }

    // Parameterized constructor
    RightAngleTriangle(int n) {
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
        RightAngleTriangle triangle(n);  // Using the parameterized constructor
    } else {
        RightAngleTriangle defaultTriangle;  // Using the default constructor
    }

    return 0;
}
