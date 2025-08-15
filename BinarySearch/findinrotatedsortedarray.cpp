#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;

        // Time Complexity: O(log n) → Binary search
        // Space Complexity: O(1) → No extra memory
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid; // Found
            }

            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Otherwise, right half is sorted
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1; // Not found
    }
};

int main() {
    Solution sol;

    // Dummy rotated sorted array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = sol.search(nums, target);

    if (result != -1)
        cout << "Target " << target << " found at index " << result << endl;
    else
        cout << "Target " << target << " not found in the array" << endl;

    return 0;
}
