#include <iostream>
using namespace std;

// Node class for Linked List
class LinkedList {
public:
    int val;
    LinkedList* next;

    LinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Queue class using singly linked list
class Queue {
private:
    LinkedList* frontNode; // Points to the front of the queue
    LinkedList* rearNode;  // Points to the rear of the queue
    int count;             // Keeps track of the number of elements

public:
    // Constructor
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Function: enqueue
    // Purpose: Add a new element to the rear of the queue
    // Time Complexity: O(1)
    void enqueue(int val) {
        LinkedList* newNode = new LinkedList(val);

        if (empty()) {
            // First element — front and rear are the same
            frontNode = rearNode = newNode;
        } else {
            // Link new node at rear
            rearNode->next = newNode;
            rearNode = newNode;
        }

        count++;
    }

    // Function: dequeue
    // Purpose: Remove and return the front element
    // Time Complexity: O(1)
    int dequeue() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }

        int value = frontNode->val;

        // Move front pointer forward and delete old node
        LinkedList* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;

        count--;

        // If the queue is now empty, rear should also be null
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        return value;
    }

    // Function: front
    // Purpose: Return the value at the front of the queue
    // Time Complexity: O(1)
    int front() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return frontNode->val;
    }

    // Function: empty
    // Purpose: Check if the queue is empty
    // Time Complexity: O(1)
    bool empty() {
        return frontNode == nullptr;
    }

    // Function: size
    // Purpose: Return number of elements in the queue
    // Time Complexity: O(1)
    int size() {
        return count;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << "\n";    // Output: 10
    cout << "Size: " << q.size() << "\n";      // Output: 3

    cout << "Dequeue: " << q.dequeue() << "\n"; // Output: 10
    cout << "Front after dequeue: " << q.front() << "\n"; // Output: 20
    cout << "Size after dequeue: " << q.size() << "\n";   // Output: 2

    return 0;
}
