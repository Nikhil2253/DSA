#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Intuitive approach using prefix and suffix arrays
    int trappingRainWaterIntuitive(vector<int> heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);
        int water = 0;

        // Compute prefix max
        prefix[0] = heights[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], heights[i]);
        }

        // Compute suffix max
        suffix[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], heights[i]);
        }

        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            int leftMax = prefix[i];
            int rightMax = suffix[i];
            water += min(leftMax, rightMax) - heights[i];
        }

        return water;

        // Time Complexity: O(n) for 3 traversals
        // Space Complexity: O(n) for prefix and suffix arrays
    }

    // Optimal approach using two pointers
    int trappingRainWaterOptimal(vector<int> heights) {
        int water = 0;
        int n = heights.size();
        int l = 0, r = n - 1;
        int lMax = 0, rMax = 0;

        while (l < r) {
            if (heights[l] <= heights[r]) {
                if (heights[l] < lMax) {
                    water += lMax - heights[l];
                } else {
                    lMax = heights[l];
                }
                l++;
            } else {
                if (heights[r] < rMax) {
                    water += rMax - heights[r];
                } else {
                    rMax = heights[r];
                }
                r--;
            }
        }

        return water;

        // Time Complexity: O(n), single traversal
        // Space Complexity: O(1), no extra space used
    }

    // Stack-based approach (Monotonic Stack)
    int trappingRainWaterStack(vector<int> heights) {
        int n = heights.size();
        int water = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] > heights[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int boundedHeight = min(heights[i], heights[st.top()]) - heights[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }

        return water;

        // Time Complexity: O(n), each bar is pushed and popped once
        // Space Complexity: O(n), for the stack
    }
};

int main() {
    Solution sol;
    vector<int> heights = {5, 2, 1, 2, 1, 5};  // Expected trapped water: 14

    cout << "Intuitive Approach: Trapped water = " << sol.trappingRainWaterIntuitive(heights) << endl;
    cout << "Optimal Approach: Trapped water = " << sol.trappingRainWaterOptimal(heights) << endl;
    cout << "Stack-Based Approach: Trapped water = " << sol.trappingRainWaterStack(heights) << endl;

    return 0;
}
