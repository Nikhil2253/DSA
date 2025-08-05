#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    // Function to check if a character is an operator
    bool isOperator(char ch) {
        return ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-';
    }

    // Function to convert postfix expression to prefix
    string postfixtoprefix(string postfix) {
        stack<string> st;  // Stack to store operands and intermediate prefix expressions
        int n = postfix.length();

        // Traverse each character of postfix expression
        for (int i = 0; i < n; i++) {
            char ch = postfix[i];

            if (isOperator(ch)) {
                // Pop two operands from stack
                string op2 = st.top(); st.pop(); // Right operand
                string op1 = st.top(); st.pop(); // Left operand

                // Combine in prefix order and push back
                string expr = ch + op1 + op2;
                st.push(expr);
            } else {
                // Push operand as string
                st.push(string(1, ch));
            }
        }

        // Final prefix expression is on top of the stack
        return st.top();
    }
};

int main() {
    Solution s;

    string postfix = "ab+c*";  // Example: (a + b) * c
    cout << "Prefix: " << s.postfixtoprefix(postfix) << endl;  // Output: *+abc

    return 0;
}
