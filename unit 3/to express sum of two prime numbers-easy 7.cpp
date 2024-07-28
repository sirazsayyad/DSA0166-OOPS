#include <iostream>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

class PrimeSumChecker {
private:
    int number;
public:
    PrimeSumChecker(int n) : number(n) {
        checkPrimeSum();
    }
    ~PrimeSumChecker() {
        cout << "PrimeSumChecker object is being destroyed." << endl;
    }

    void checkPrimeSum() {
        bool found = false;
        for (int i = 2; i <= number / 2; ++i) {
            if (isPrime(i) && isPrime(number - i)) {
                cout << number << " can be expressed as the sum of " << i << " and " << number - i << " (both prime numbers)." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << number << " cannot be expressed as the sum of two prime numbers." << endl;
        }
    }
};

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n > 0) {
        PrimeSumChecker checker(n); 
    } else {
        cout << "Invalid input! Please enter a positive integer." << endl;
    }

    return 0;
}
