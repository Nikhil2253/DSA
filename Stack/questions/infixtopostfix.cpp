#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to return precedence of operators
    int priority(char op) {
        if (op == '^') return 3; // Highest precedence
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '+' || op == '-') return 1;
        return 0; // For non-operators like '('
    }

    // Function to check right-associativity (only ^ is right-associative)
    bool isRightAssociative(char op) {
        return op == '^';
    }

    // Main function to convert infix to postfix
    string infixtopostfix(string infix) {
        stack<char> st; // Operator stack
        string ans = ""; // Resulting postfix expression

        int n = infix.length();
        for (int i = 0; i < n; i++) {
            char ch = infix[i];

            // 1. If operand (letter or digit), directly add to output
            if (isalnum(ch)) {
                ans += ch;
            }

            // 2. If '(', push to stack
            else if (ch == '(') {
                st.push(ch);
            }

            // 3. If ')', pop until '('
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // Remove the '(' from stack
                }
            }

            // 4. If operator
            else {
                while (!st.empty() && (
                    (priority(ch) < priority(st.top())) ||
                    (priority(ch) == priority(st.top()) && !isRightAssociative(ch))
                ) && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // 5. Pop remaining operators from stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample expression: (A+B)*C^D-E
    string infix = "(A+B)*C^D-E";
    string postfix = sol.infixtopostfix(infix);

    cout << "Infix:    " << infix << endl;
    cout << "Postfix:  " << postfix << endl;

    return 0;
}
