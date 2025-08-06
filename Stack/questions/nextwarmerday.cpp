#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> result(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top().second - i;
            }

            st.push({temperatures[i], i});
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
