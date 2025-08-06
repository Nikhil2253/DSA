#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Previous Smaller Element
    vector<int> prevSmaller(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    // Next Smaller Element
    vector<int> nextSmaller(const vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    // Previous Greater Element
    vector<int> prevGreater(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    // Next Greater Element
    vector<int> nextGreater(const vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    // Main function to compute sum of subarray ranges
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevMin = prevSmaller(nums);
        vector<int> nextMin = nextSmaller(nums);
        vector<int> prevMax = prevGreater(nums);
        vector<int> nextMax = nextGreater(nums);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - prevMin[i];
            long long rightMin = nextMin[i] - i;
            minSum += leftMin * rightMin * (long long)nums[i];

            long long leftMax = i - prevMax[i];
            long long rightMax = nextMax[i] - i;
            maxSum += leftMax * rightMax * (long long)nums[i];
        }

        return maxSum - minSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    cout << "Sum of Subarray Ranges: " << sol.subArrayRanges(nums) << endl;

    return 0;
}
