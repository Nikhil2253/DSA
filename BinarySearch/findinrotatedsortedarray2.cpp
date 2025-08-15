#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;

        // Time Complexity: O(n) in worst case due to duplicates
        // Space Complexity: O(1)
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true; // Found
            }

            // Handle duplicates — shrink the search space
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Left half sorted
            else if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false; // Not found
    }
};

int main() {
    Solution sol;

    // Test case with duplicates
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool found = sol.search(nums, target);

    if (found)
        cout << "Target " << target << " found in the array" << endl;
    else
        cout << "Target " << target << " not found in the array" << endl;

    return 0;
}
