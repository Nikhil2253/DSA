#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // TC: O(n), SC: O(n)
    vector<int> prevSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    // TC: O(n), SC: O(n)
    vector<int> nextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    // TC: O(n), SC: O(n)
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> prev = prevSmallerIndex(arr);
        vector<int> next = nextSmallerIndex(arr);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contrib = (left * right % mod) * arr[i] % mod;
            sum = (sum + contrib) % mod;
        }

        return (int)sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(arr) << endl;
    return 0;
}
