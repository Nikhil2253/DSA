#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        bool isOdd = (total % 2 == 1);
        int mid = total / 2;

        int prev = 0, curr = 0;

        // Time Complexity: O(n + m) in worst case (but stops early at mid)
        // Space Complexity: O(1) — uses only constant extra space
        for (int k = 0; k <= mid; k++) {
            prev = curr;
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }

        return isOdd ? curr : (prev + curr) / 2.0;
    }
};

int main() {
    vector<int> nums1 = {1, 4, 7, 10, 13, 16, 19};
    vector<int> nums2 = {2, 5, 8, 11, 14, 17, 20};

    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}
