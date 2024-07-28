#include <iostream>

template <typename T>
class Stack {
private:
    T* stack;
    int top;
    int size;
public:
    Stack(int s) {
        size = s;
        stack = new T[size];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T value);
    T pop();
    bool isEmpty();
    bool isFull();
    void display();
};

template <typename T>
void Stack<T>::push(T value) {
    if (isFull()) {
        std::cout << "Stack is full" << std::endl;
        return;
    }
    stack[++top] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return T(); // return default value
    }
    return stack[top--];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
    return top == size - 1;
}

template <typename T>
void Stack<T>::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    for (int i = 0; i <= top; i++)
        std::cout << stack[i] << " ";
    std::cout << std::endl;
}

int main() {
    Stack<int> s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
