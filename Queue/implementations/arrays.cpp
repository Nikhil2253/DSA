#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = 0;
    }

    // Add element to the rear
    void enqueue(int val) {
        if (full()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rearIndex++] = val;
    }

    // Remove and return the front element
    int dequeue() {
        if (empty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }

    // Get the current front value
    int front() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Check if queue is empty
    bool empty() {
        return frontIndex == rearIndex;
    }

    // Check if queue is full
    bool full() {
        return rearIndex == MAX;
    }

    // Return current size of the queue
    int size() {
        return rearIndex - frontIndex;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front after dequeue: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
