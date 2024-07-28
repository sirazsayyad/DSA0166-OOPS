#include <iostream>
#include <exception>
using namespace std;

class SmallNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "The number is too small";
    }
};

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "The number is negative";
    }
};

class NonIntegerException : public exception {
public:
    const char* what() const noexcept override {
        return "The number is not an integer";
    }
};

void checkNumber(double x) {
    if (x < 0) {
        throw NegativeNumberException();
    } else if (x != static_cast<int>(x)) {
        throw NonIntegerException();
    } else if (x < 1) {
        throw SmallNumberException();
    }
}

int main() {
    double x;
    cout << "Enter a number: ";
    cin >> x;

    try {
        checkNumber(x);
        cout << "The number is valid: " << static_cast<int>(x) << endl;
    } catch (const SmallNumberException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const NegativeNumberException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const NonIntegerException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Error: Unknown exception" << endl;
    }

    return 0;
}
