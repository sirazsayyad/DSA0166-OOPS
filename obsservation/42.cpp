#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(T value);
    void remove(T value);
    void display();
};

template <typename T>
void LinkedList<T>::insert(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::remove(T value) {
    if (!head) return;
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node<T>* temp = head;
    while (temp->next && temp->next->data != value) temp = temp->next;
    if (temp->next) {
        Node<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::display() {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList<int> ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.display();
    ll.remove(20);
    ll.display();
    return 0;
}
