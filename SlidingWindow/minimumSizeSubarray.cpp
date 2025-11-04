#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int optimalApproach(vector<int> nums, int target) {
    int n = nums.size();
    int mini = INT_MAX;

    int i = 0, sum = 0;

    for (int j = 0; j < n; j++) {
        sum += nums[j];

        while (sum >= target) {
            mini = min(mini, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }

    return (mini == INT_MAX) ? 0 : mini;
}

int bruteForce(vector<int> nums, int target) {
    int n = nums.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        int tempSum = 0;
        for (int j = i; j < n; j++) {
            tempSum += nums[j];
            if (tempSum >= target) {
                mini = min(mini, j - i + 1);
                break;
            }
        }
    }

    return (mini == INT_MAX) ? 0 : mini;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Brute Force: " << bruteForce(nums, target) << endl;
    cout << "Optimal: " << optimalApproach(nums, target) << endl;

    return 0;
}
