#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> previousSmallestElement(vector<int> arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pse[i] = st.top();
            }

            st.push(arr[i]);
        }

        return pse;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = sol.previousSmallestElement(arr);

    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}
