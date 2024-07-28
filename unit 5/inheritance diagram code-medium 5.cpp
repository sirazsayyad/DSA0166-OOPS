#include <iostream>
using namespace std;

class Principal {
protected:
    double principalAmount;
public:
    void getPrincipal() {
        cout << "Enter the principal Amount: ";
        cin >> principalAmount;
    }
};

class Duration : public Principal {
protected:
    int years;
public:
    void getDuration() {
        cout << "Enter the No. of years: ";
        cin >> years;
    }
};

class RateOfInterest : public Duration {
protected:
    double rate;
public:
    void getRate() {
        cout << "Enter the rate of Interest: ";
        cin >> rate;
    }
};

class SimpleInterest : public RateOfInterest {
public:
    void calculateInterest() {
        double simpleInterest = (principalAmount * years * rate) / 100;
        cout << "Simple Interest: " << simpleInterest << endl;
    }
};

int main() {
    SimpleInterest si;
    si.getPrincipal();
    si.getDuration();
    si.getRate();
    si.calculateInterest();
    
    return 0;
}
