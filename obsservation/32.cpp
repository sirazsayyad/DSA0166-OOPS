#include <iostream>
#define MAX 100

class CircularQueue {
private:
    int front, rear, size;
    int* queue;
public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int value);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

void CircularQueue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    queue[rear] = value;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    int value = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % size;
    return value;
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

bool CircularQueue::isFull() {
    return (rear + 1) % size == front;
}

void CircularQueue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    int i = front;
    while (i != rear) {
        std::cout << queue[i] << " ";
        i = (i + 1) % size;
    }
    std::cout << queue[rear] << std::endl;
}

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    return 0;
}
