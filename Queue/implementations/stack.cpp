#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2; // s1 for enqueue, s2 for dequeue
    int currSize;

public:
    Queue() {
        currSize = 0;
    }

    // Enqueue operation: O(1)
    void enqueue(int val) {
        s1.push(val); // push into s1 directly
        currSize++;
    }

    // Dequeue operation: Amortized O(1), Worst-case O(n)
    int dequeue() {
        if (s2.empty()) {
            // Transfer all elements from s1 to s2 only when s2 is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int frontVal = s2.top();
        s2.pop();
        currSize--;
        return frontVal;
    }

    // Front operation: Amortized O(1), Worst-case O(n)
    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s2.top();
    }

    // Size operation: O(1)
    int size() {
        return currSize;
    }

    // Empty check: O(1)
    bool empty() {
        return currSize == 0;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl;    // 10
    cout << "Front after dequeue: " << q.front() << endl; // 20

    cout << "Size: " << q.size() << endl; // 2
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << endl; // No

    return 0;
}
