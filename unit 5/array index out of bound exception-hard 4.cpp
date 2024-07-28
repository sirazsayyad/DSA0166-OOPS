#include <iostream>
#include <exception>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index;

    cout << "Enter the index to access: ";
    cin >> index;

    try {
        if (index < 0 || index >= 5) {
            throw out_of_range("Array index out of bounds");
        }
        cout << "Value at index " << index << ": " << arr[index] << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
