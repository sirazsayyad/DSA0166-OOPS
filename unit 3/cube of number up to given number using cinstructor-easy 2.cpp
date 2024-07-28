#include <iostream>
using namespace std;

class CubeCalculator {
public:
    int number;
    CubeCalculator() : number(0) {
        displayCube();
    }
    CubeCalculator(int n) : number(n) {
        displayCube();
    }

    void displayCube() {
        cout << "Cube of " << number << " is " << (number * number * number) << endl;
    }
};

int main() {
    int limit;

    cout << "Enter a positive integer: ";
    cin >> limit;

    for (int i = 1; i <= limit; ++i) {
        CubeCalculator calculator(i);
    }

    return 0;
}
