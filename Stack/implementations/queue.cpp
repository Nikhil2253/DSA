#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    static const int MAX = 100; // max size limit
    queue<int> q;               // single queue to simulate stack
    int currSize;               // track current stack size

public:
    Stack() {
        currSize = 0;
    }

    // Push operation: O(n)
    void push(int val) {
        if (currSize == MAX) {
            cout << "Stack is full\n";
            return;
        }

        q.push(val); // Push the new element

        // Rotate all previous elements behind the new one to maintain stack order
        for (int i = 0; i < currSize; ++i) {
            q.push(q.front());
            q.pop();
        }

        currSize++; // Increase size
    }

    // Pop operation: O(1)
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int topElement = q.front();
        q.pop();
        currSize--;
        return topElement;
    }

    // Top operation: O(1)
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        return q.front();
    }

    // Check if stack is empty: O(1)
    bool empty() {
        return q.empty();
    }

    // Check if stack is full: O(1)
    bool full() {
        return currSize == MAX;
    }

    // Get current size: O(1)
    int size() {
        return currSize;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl;     // 30
    cout << "Pop: " << s.pop() << endl;     // 30
    cout << "Top: " << s.top() << endl;     // 20
    cout << "Size: " << s.size() << endl;   // 2
    cout << "Empty: " << s.empty() << endl; // 0 (false)
    return 0;
}
