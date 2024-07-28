#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
bool isEmpty(Node* top) {
    return top == nullptr;
}
void push(Node*& top, int data) {
    Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    cout << data << " pushed to stack\n";
}
int pop(Node*& top) {
    if (isEmpty(top)) {
        cout << "Stack Underflow\n";
        exit(1);
    }
    Node* temp = top;
    top = top->next;
    int popped = temp->data;
    delete temp;
    return popped;
}
int peek(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack is empty\n";
        exit(1);
    }
    return top->data;
}
int main() {
    Node* stack = nullptr;
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    cout << peek(stack) << " is the top element of the stack\n";
    cout << pop(stack) << " popped from stack\n";
    cout << pop(stack) << " popped from stack\n";
    cout << "Is stack empty? " << (isEmpty(stack) ? "Yes" : "No") << endl;
    return 0;
}
