#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int lowerBound(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    // Intuitive O(n) approach (linear scan)
    pair<int,int> intuitiveSimpleFirstandLastOccurence(vector<int> nums, int target){
        int first = -1, last = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (first == -1) first = i;  // record first once
                last = i;                    // keep updating last
            }
        }
        return {first, last};
    }

    // Better O(2·log n) approach (two binary searches)
    pair<int, int> betterFirstandLastOccurence(vector<int> nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        if (first == nums.size() || nums[first] != target) return {-1, -1};
        return {first, last};
    }

    // Optimal O(log n) approach (single binary search)
    pair<int,int> optimalFirstandLastOccurence(vector<int> nums, int target){
        int first = -1, last = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                if (first == -1) first = mid;
                first = min(first, mid);
                last = max(last, mid);

                // shrink search both sides
                if (nums[low] == target) first = low;
                if (nums[high] == target) last = high;

                low++;
                high--;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {first, last};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    auto ans1 = s.intuitiveSimpleFirstandLastOccurence(nums, target);
    cout << "[O(n) approach] First Occurrence: " << ans1.first << ", Last Occurrence: " << ans1.second << endl;

    auto ans2 = s.betterFirstandLastOccurence(nums, target);
    cout << "[O(2·log n) approach] First Occurrence: " << ans2.first << ", Last Occurrence: " << ans2.second << endl;

    auto ans3 = s.optimalFirstandLastOccurence(nums, target);
    cout << "[O(log n) approach] First Occurrence: " << ans3.first << ", Last Occurrence: " << ans3.second << endl;

    return 0;
}
