#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    // TC: O(n) - Each character is processed once
    // SC: O(n) - Stack holds intermediate expressions

    // Check if a character is an operator
    bool isOperator(char ch)
    {
        return ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-';
    }

    // Convert prefix to postfix
    string prefixtopostfix(string prefix)
    {
        stack<string> st;
        int n = prefix.length();

        // Traverse prefix from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = prefix[i];

            if (isOperator(ch))
            {
                // Pop two operands
                string op1 = st.top(); st.pop();  // First operand (left)
                string op2 = st.top(); st.pop();  // Second operand (right)

                // Form postfix: op1 op2 operator
                string newTop = op1 + op2 + ch;
                st.push(newTop);
            }
            else
            {
                // Operand pushed as string
                st.push(string(1, ch));
            }
        }

        // Final postfix expression
        return st.top();
    }
};

int main()
{
    Solution s;

    string prefix = "*+AB-CD";  // Equivalent to: (A + B) * (C - D)
    cout << "Postfix: " << s.prefixtopostfix(prefix) << endl;  // Output: AB+CD-*

    return 0;
}
