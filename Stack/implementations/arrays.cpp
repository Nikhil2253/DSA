#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    // Push an element to the stack O(1)
    void push(int val) {
        if (full()) {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    // Pop an element from the stack O(1)
    int pop() {
        if (empty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1; // or throw an exception
        }
        return arr[topIndex--];
    }

    // Get the top element O(1)
    int peek() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty O(1)
    bool empty() {
        return topIndex == -1;
    }

    // Check if stack is full O(1)
    bool full() {
        return topIndex == MAX - 1;
    }

    // Get current size of stack O(1)
    int size() {
        return topIndex + 1;
    }
};

int main() {
    
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while(!st.empty()){
        cout<<st.pop()<<endl;
    }

    return 0;
}
