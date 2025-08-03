#include<iostream>   
#include<stack>      

using namespace std;   

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else {
                if (st.empty()) return false;
                
                if ((c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {

    Solution sol;

    string test = "({[]})";
    bool result = sol.isValid(test);

    cout << (result ? "Valid" : "Invalid") << endl;

    return 0; 
}
