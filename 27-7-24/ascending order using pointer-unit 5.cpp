#include <iostream>
using namespace std;

void sortArray(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int *arr = new int[100]; // Allocating a large array
    int n = 0;
    int input;

    cout << "Enter Infinite Numbers and (-1 To Stop Reading)" << endl;
    while(true) {
        cin >> input;
        if(input == -1) break;
        arr[n++] = input;
    }

    sortArray(arr, n);

    cout << "The Ascending order is given below:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr; // Free the allocated memory
    return 0;
}
