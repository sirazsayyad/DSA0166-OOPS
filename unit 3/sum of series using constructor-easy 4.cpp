#include <iostream>
#include<cmath>
using namespace std;

class SeriesSum {
public:
    int sum;
    SeriesSum() : sum(0) {
        displaySum();
    }
    SeriesSum(int n, int d) {
        sum = n * (2 + (n - 1) * d) / 2;
        displaySum();
    }
    
    SeriesSum(int n, double a, double r) {
        sum = a * (1 - pow(r, n)) / (1 - r);
        displaySum();
    }

    void displaySum() {
        cout << "Sum of the series is " << sum << endl;
    }
};

int main() {
    int choice;
    cout << "Choose the series type:\n";
    cout << "1. Arithmetic Series\n";
    cout << "2. Geometric Series\n";
    cin >> choice;

    if (choice == 1) {
        int n, d;
        cout << "Enter the number of terms (n): ";
        cin >> n;
        cout << "Enter the common difference (d): ";
        cin >> d;
        SeriesSum arithmeticSum(n, d);
    } else if (choice == 2) {
        int n;
        double a, r;
        cout << "Enter the number of terms (n): ";
        cin >> n;
        cout << "Enter the first term (a): ";
        cin >> a;
        cout << "Enter the common ratio (r): ";
        cin >> r;
        SeriesSum geometricSum(n, a, r);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
