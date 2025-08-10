#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removekdigits(string digits, int k) {
        stack<char> st;
        for (char d : digits) {
            while (!st.empty() && k > 0 && st.top() > d) {
                st.pop();
                k--;
            }
            st.push(d);
        }

        // If we still need to remove digits
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') start++;
        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution s;
    cout << s.removekdigits("1432219", 3) << endl; // Expected "1219"
    cout << s.removekdigits("10200", 1) << endl;   // Expected "200"
    cout << s.removekdigits("10", 2) << endl;      // Expected "0"
}
