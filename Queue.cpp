#include "Queue.h"

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr), count(0) {}

Queue::~Queue() {
    while (!isEmpty())
        dequeue();
}

void Queue::enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw "Queue is empty";

    int frontValue = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    count--;

    if (isEmpty())
        rear = nullptr;

    return frontValue;
}

int Queue::getFront() const {
    if (isEmpty())
        throw "Queue is empty";

    return front->data;
}

bool Queue::isEmpty() const {
    return count == 0;
}

size_t Queue::size() const {
    return count;
}