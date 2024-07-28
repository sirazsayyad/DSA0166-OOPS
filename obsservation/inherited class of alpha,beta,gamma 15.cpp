#include <iostream>
using namespace std;

class Alpha {
public:
    Alpha() {
        cout << "Alpha constructor called." << endl;
    }
    ~Alpha() {
        cout << "Alpha destructor called." << endl;
    }
};

class Beta {
public:
    Beta() {
        cout << "Beta constructor called." << endl;
    }
    ~Beta() {
        cout << "Beta destructor called." << endl;
    }
};

class Gamma : public Alpha, public Beta {
public:
    Gamma() {
        cout << "Gamma constructor called." << endl;
    }
    ~Gamma() {
        cout << "Gamma destructor called." << endl;
    }
};

int main() {
    Gamma g;

    return 0;
}
