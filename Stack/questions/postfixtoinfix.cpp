#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    // Function to check if the character is an operator
    bool isOperator(char ch) {
        return ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-';
    }

    // Function to convert postfix expression to infix
    string postfixtoinfix(string postfix) {
        stack<string> st; // Stack to store intermediate infix expressions
        int n = postfix.length();

        for (int i = 0; i < n; i++) {
            char ch = postfix[i];

            if (isOperator(ch)) {
                // Pop the two topmost operands from the stack
                string op2 = st.top(); st.pop();  // Second operand
                string op1 = st.top(); st.pop();  // First operand

                // Form the infix expression with parentheses
                string expr = "(" + op1 + ch + op2 + ")";

                // Push the new expression back onto the stack
                st.push(expr);
            } else {
                // If character is an operand, push it as a string
                st.push(string(1, ch));
            }
        }

        // Final element of stack is the complete infix expression
        return st.top();
    }
};

int main() {
    Solution s;

    // Sample postfix expression
    string postfix = "ab+c*";

    // Output the result of conversion
    cout << "Infix: " << s.postfixtoinfix(postfix) << endl;

    return 0;
}
