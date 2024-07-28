#include <iostream>
using namespace std;

class DivisibleByNine {
private:
    int start, end;
    int sum;

    void calculateNumbers() {
        sum = 0;
        cout << "Numbers between " << start << " and " << end << " divisible by 9 are:" << endl;
        for (int i = start; i <= end; ++i) {
            if (i % 9 == 0) {
                cout << i << " ";
                sum += i;
            }
        }
        cout << endl;
    }

public:
    DivisibleByNine(int s, int e) : start(s), end(e), sum(0) {
        calculateNumbers();
        displaySum();
    }
    ~DivisibleByNine() {
        cout << "DivisibleByNine object is being destroyed." << endl;
    }

    void displaySum() {
        cout << "Sum of numbers divisible by 9 between " << start << " and " << end << " is: " << sum << endl;
    }
};

int main() {
    DivisibleByNine checker(100, 200); 

    return 0;
}
