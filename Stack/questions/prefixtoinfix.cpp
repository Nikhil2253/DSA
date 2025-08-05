#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Check if character is an operator
    bool isOperator(char ch) {
        return ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-';
    }

    // Function to convert prefix to infix
    string prefixtoinfix(string prefix) {
        stack<string> st;
        int n = prefix.length();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            char ch = prefix[i];

            if (isOperator(ch)) {
                // Pop two operands
                string op1 = st.top(); st.pop(); // First operand (left)
                string op2 = st.top(); st.pop(); // Second operand (right)

                // Form new expression and push back
                string expr = "(" + op1 + ch + op2 + ")";
                st.push(expr);
            } else {
                // Operand as string
                st.push(string(1, ch));
            }
        }

        return st.top();
    }
};

int main() {
    Solution s;

    string prefix = "*+ab-cd"; // Example: (a + b) * (c - d)
    cout << "Infix: " << s.prefixtoinfix(prefix) << endl;

    return 0;
}
