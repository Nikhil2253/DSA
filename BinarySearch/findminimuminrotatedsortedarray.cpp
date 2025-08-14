#include <bits/stdc++.h>
using namespace std;

// Problem: Find Minimum in Rotated Sorted Array
// Given a rotated sorted array (no duplicates), 
// return the minimum element in O(log n) time.
/*
Time Complexity: O(log n)
  - Binary search approach halves the search space in every iteration.
Space Complexity: O(1)
  - No extra space is used, only a few integer variables.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;        // Initialize answer with maximum integer
        int low = 0;              // Start of the search range
        int high = nums.size() - 1; // End of the search range

        // Binary search loop
        while(low <= high){
            int mid = low + (high - low) / 2; // Avoid overflow

            // If current range is already sorted, the smallest element is at low
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break; // Found the minimum, exit loop
            }

            // Left half is sorted, minimum must be in the right half
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1; // Search in right half
            }
            else {
                // Right half is sorted or contains minimum
                ans = min(ans, nums[mid]);
                high = mid - 1; // Search in left half
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,2,3,3,3}; // Example input
    cout << "Minimum element: " << sol.findMin(nums) << endl;
    return 0;
}

