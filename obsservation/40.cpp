#include <iostream>
#include <string>

template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int intArr[] = {5, 2, 9, 1, 5, 6};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    sortArray(intArr, intSize);
    printArray(intArr, intSize);

    float floatArr[] = {4.2, 2.1, 5.5, 3.3};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    sortArray(floatArr, floatSize);
    printArray(floatArr, floatSize);

    std::string stringArr[] = {"apple", "orange", "banana", "grape"};
    int stringSize = sizeof(stringArr) / sizeof(stringArr[0]);
    sortArray(stringArr, stringSize);
    printArray(stringArr, stringSize);

    return 0;
}
