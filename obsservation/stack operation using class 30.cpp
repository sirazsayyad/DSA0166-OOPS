#include <iostream>
using namespace std;

// Define maximum size of the stack
const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top to -1 indicating empty stack
    }

    // Push operation: add element to the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements.\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack.\n";
        }
    }

    // Pop operation: remove element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
        } else {
            int poppedValue = arr[top--];
            cout << poppedValue << " popped from stack.\n";
        }
    }

    // Utility function: Display elements in the stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; --i) {
                cout << arr[i] << "\n";
            }
        }
    }
};

int main() {
    Stack stack;

    // Demonstrate stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    return 0;
}
