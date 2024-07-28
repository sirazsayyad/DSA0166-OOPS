#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero error";
    }
    return (double)a / b;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try {
        double result = divide(num1, num2);
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}
