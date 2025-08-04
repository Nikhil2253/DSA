#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class NonOptimalMinStack { // Not optimal — uses extra space via pair<int, int>
private:
    stack<pair<int, int>> st;

public:
    NonOptimalMinStack() {} // TC: O(1)

    // TC: O(1)
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currMin = min(val, st.top().second);
            st.push({val, currMin});
        }
    }

    // TC: O(1)
    int pop() {
        int val = st.top().first;
        st.pop();
        return val;
    }

    // TC: O(1)
    int top() {
        return st.top().first;
    }

    // TC: O(1)
    int getMin() {
        return st.top().second;
    }

    // TC: O(1)
    bool empty() {
        return st.empty();
    }
};

class MinStack { // Optimal — No extra space for storing min
private:
    stack<long long> st;
    long long minimum;

public:
    MinStack() {
        minimum = 0;
    }

    // TC: O(1)
    void push(int val) {
        if (st.empty()) {
            minimum = val;
            st.push(val);
        } else {
            if (val >= minimum) {
                st.push(val);
            } else {
                st.push(2LL * val - minimum); // encoded value
                minimum = val;
            }
        }
    }

    // TC: O(1)
    int pop() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        st.pop();

        if (topVal < minimum) {
            // Decoding previous minimum
            int actual = minimum;
            minimum = 2 * minimum - topVal;
            return actual;
        }

        return topVal;
    }

    // TC: O(1)
    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        if (topVal < minimum) {
            return minimum;
        }
        return topVal;
    }

    // TC: O(1)
    int getMin() {
        return minimum;
    }

    // TC: O(1)
    bool empty() {
        return st.empty();
    }
};

int main() {
    NonOptimalMinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);

    cout << "NonOptimal Stack\n";
    cout << "Top: " << ms.top() << endl;           // Output: 7
    cout << "Min: " << ms.getMin() << endl;        // Output: 3
    ms.pop();
    cout << "Min after pop: " << ms.getMin() << endl; // Output: 3

    cout << "\nOptimal Stack\n";
    MinStack opt;
    opt.push(5);
    opt.push(3);
    opt.push(7);

    cout << "Top: " << opt.top() << endl;          // Output: 7
    cout << "Min: " << opt.getMin() << endl;       // Output: 3
    opt.pop();
    cout << "Min after pop: " << opt.getMin() << endl; // Output: 3

    return 0;
}
