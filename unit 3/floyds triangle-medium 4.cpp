#include <iostream>
using namespace std;

class FloydsTriangle {
private:
    int rows; 

public:
    FloydsTriangle(int r) : rows(r) {
        printTriangle();
    }
    void printTriangle() {
        int num = 1;  
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= i; ++j) {
                cout << num << " ";
                ++num;
            }
            cout << endl;
        }
    }
    ~FloydsTriangle() {
        cout << "Floyd's Triangle with " << rows << " rows has been printed." << endl;
    }
};

int main() {
    int n;

    cout << "Enter the number of rows for Floyd's Triangle: ";
    cin >> n;

    if (n > 0) {
        FloydsTriangle triangle(n);  
    } else {
        cout << "Number of rows must be greater than 0." << endl;
    }

    return 0;
}

