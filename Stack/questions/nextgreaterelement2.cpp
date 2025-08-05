#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Function to find next greater elements in a circular array
    vector<int> nextGreaterElements(vector<int> nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  // Initialize result vector with -1s
        stack<int> st;           // Stack to keep potential next greater elements

        // Traverse the array from 2n-1 to 0 to simulate circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            int current = nums[i % n];  // Use modulo to wrap around

            // Maintain decreasing stack: Pop smaller/equal elements
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // Only fill result during the first pass (i < n)
            if (i < n) {
                if (!st.empty()) {
                    nge[i] = st.top();  // Top is next greater element
                } 
                // Else, nge[i] remains -1
            }

            // Push current element for future comparisons
            st.push(current);
        }

        return nge;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};

    // Get the result
    vector<int> result = sol.nextGreaterElements(nums);

    // Print the result
    cout << "Next Greater Elements (circular): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
