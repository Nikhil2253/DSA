#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > temp.back()) {
            temp.push_back(nums[i]);
        } else {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            *it = nums[i];
        }
    }

    return temp.size();
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = lengthOfLIS(nums);

    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
