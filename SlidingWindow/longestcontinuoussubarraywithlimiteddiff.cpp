#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDq, minDq;
        int i = 0, longest = 0;

        for (int j = 0; j < nums.size(); j++) {
            while (!maxDq.empty() && nums[j] > maxDq.back()) 
                maxDq.pop_back();
            maxDq.push_back(nums[j]);

            while (!minDq.empty() && nums[j] < minDq.back()) 
                minDq.pop_back();
            minDq.push_back(nums[j]);

            while (!maxDq.empty() && !minDq.empty() && maxDq.front() - minDq.front() > limit) {
                if (nums[i] == maxDq.front()) maxDq.pop_front();
                if (nums[i] == minDq.front()) minDq.pop_front();
                i++;
            }

            longest = max(longest, j - i + 1);
        }

        return longest;
    }
};
