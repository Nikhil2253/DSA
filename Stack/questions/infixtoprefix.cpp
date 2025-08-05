#include <iostream>
#include <stack>
#include <algorithm>  // for reverse
using namespace std;

class Solution {
public:
    // Helper function to define precedence of operators
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    // Helper function to check if character is an operator
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }

    // Main function: Convert infix to prefix
    string infixToPrefix(string infix) {
        // Time Complexity (TC): O(n)
        // - We traverse the expression twice: once for reversal and once for processing
        // - Each character is pushed and popped at most once from the stack

        // Space Complexity (SC): O(n)
        // - Stack used for operators
        // - String for result

        // Step 1: Reverse the infix expression
        reverse(infix.begin(), infix.end());

        // Step 2: Change '(' to ')' and vice versa
        for (int i = 0; i < infix.size(); i++) {
            if (infix[i] == '(') infix[i] = ')';
            else if (infix[i] == ')') infix[i] = '(';
        }

        stack<char> st;        // operator stack
        string prefix = "";    // result string

        // Step 3: Convert to postfix (on reversed expression)
        for (char ch : infix) {
            if (isalnum(ch)) {
                // If operand, add directly to result
                prefix += ch;
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    prefix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            }
            else if (isOperator(ch)) {
                while (!st.empty() && precedence(st.top()) > precedence(ch)) {
                    prefix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            prefix += st.top();
            st.pop();
        }

        // Step 4: Reverse the result to get the final prefix
        reverse(prefix.begin(), prefix.end());

        return prefix;
    }
};

int main() {
    Solution sol;
    string infix = "(A-B/C)*(A/K-L)";
    string prefix = sol.infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}
