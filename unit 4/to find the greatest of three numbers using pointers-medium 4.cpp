#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    int *p1, *p2, *p3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    p1 = &num1;
    p2 = &num2;
    p3 = &num3;

    int greatest = (*p1 > *p2) ? ((*p1 > *p3) ? *p1 : *p3) : ((*p2 > *p3) ? *p2 : *p3);

    cout << "Greatest number is: " << greatest << endl;

    return 0;
}
