#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearSearchPeakElement(vector<int>& nums) {// Time Complexity: O(n)
        int n = nums.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            bool leftOk = (i == 0) || (nums[i] > nums[i - 1]);
            bool rightOk = (i == n - 1) || (nums[i] > nums[i + 1]);
            if (leftOk && rightOk) return i;
        }
        return -1;
    }

    int binarySearchPeakElement(vector<int>& nums) {// Time Complexity: O(log n)
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid-1] > nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    vector<int> nums3 = {10};

    cout << "Array 1: Linear = " << sol.linearSearchPeakElement(nums1)
         << ", Binary = " << sol.binarySearchPeakElement(nums1) << endl;

    cout << "Array 2: Linear = " << sol.linearSearchPeakElement(nums2)
         << ", Binary = " << sol.binarySearchPeakElement(nums2) << endl;

    cout << "Array 3: Linear = " << sol.linearSearchPeakElement(nums3)
         << ", Binary = " << sol.binarySearchPeakElement(nums3) << endl;

    return 0;
}
