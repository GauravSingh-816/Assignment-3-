#include <cstddef>

using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
    std::size_t count;

public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
    std::size_t size() const;
};