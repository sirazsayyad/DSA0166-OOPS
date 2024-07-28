#include <iostream>
using namespace std;

class Number {
protected:
    int M;
    int N;
    int K;
public:
    void getInput() {
        cout << "Enter the start number (M): ";
        cin >> M;
        cout << "Enter the end number (N): ";
        cin >> N;
        cout << "Enter the skipping number (K): ";
        cin >> K;
    }
    
    virtual void printSequence() = 0;
};

class Skipper : public Number {
public:
    void printSequence() override {
        for (int i = M; i <= N; i += K + 1) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Skipper skipper;
    skipper.getInput();  
    skipper.printSequence();
    
    return 0;
}
