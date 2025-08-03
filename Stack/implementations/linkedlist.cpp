#include <iostream>
using namespace std;

// Node structure
class LinkedList {
public:
    int val;
    LinkedList *next;

    LinkedList(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class Stack {
private:
    LinkedList *topNode;  // Pointer to the top node of the stack
    int count;            // Number of elements in the stack

public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Push: insert at head
    void push(int val) {
        LinkedList *newNode = new LinkedList(val);
        newNode->next = topNode;  // new node points to current top
        topNode = newNode;        // update top to new node
        count++;
    }

    // Pop: remove from head
    int pop() {
        if (empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int val = topNode->val;
        LinkedList *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return val;
    }

    // Top: get value at top without popping
    int top() {
        if (empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->val;
    }

    bool empty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "New Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    return 0;
}
