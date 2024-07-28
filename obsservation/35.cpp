#include <iostream>

class Queue {
private:
    int* queue;
    int front, rear, size;
public:
    Queue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int value);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

void Queue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    int value = queue[front];
    if (front >= rear) front = rear = -1;
    else front++;
    return value;
}

bool Queue::isEmpty() {
    return front == -1;
}

bool Queue::isFull() {
    return rear == size - 1;
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    for (int i = front; i <= rear; i++)
        std::cout << queue[i] << " ";
    std::cout << std::endl;
}

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
