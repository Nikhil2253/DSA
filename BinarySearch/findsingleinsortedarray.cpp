#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // O(N) Intuitive Linear Scan
    int intuitiveSimpleApproach(vector<int> nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (nums[i] != nums[i + 1])
                    return nums[i];
            }
            else if (i == n - 1)
            {
                if (nums[i] != nums[i - 1])
                    return nums[i];
            }
            else
            {
                if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                    return nums[i];
            }
        }
        return -1;
    }

    // O(logN) Binary Search Optimal
    int betterOptimalApproach(vector<int> nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Found the unique element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // If mid is even and nums[mid] == nums[mid+1], the unique is on right
            // Or if mid is odd and nums[mid] == nums[mid-1], the unique is on right
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    vector<int> nums2 = {10, 10, 11};
    vector<int> nums3 = {7};

    cout << "Intuitive: " << sol.intuitiveSimpleApproach(nums1) << endl; // 3
    cout << "Optimal: " << sol.betterOptimalApproach(nums1) << endl;    // 3

    cout << "Intuitive: " << sol.intuitiveSimpleApproach(nums2) << endl; // 11
    cout << "Optimal: " << sol.betterOptimalApproach(nums2) << endl;    // 11

    cout << "Intuitive: " << sol.intuitiveSimpleApproach(nums3) << endl; // 7
    cout << "Optimal: " << sol.betterOptimalApproach(nums3) << endl;    // 7

    return 0;
}
