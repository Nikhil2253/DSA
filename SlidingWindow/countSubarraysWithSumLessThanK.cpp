#include <iostream>
#include <vector>
using namespace std;

long long bruteForce(vector<int>& nums, long long k) {
    int n = nums.size();
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            long long len = j - i + 1;
            if (sum * len < k) count++;
        }
    }
    return count;
}

long long optimalApproach(vector<int>& nums, long long k) {
    long long sum = 0, count = 0;
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        while (sum * (j - i + 1LL) >= k) {
            sum -= nums[i];
            i++;
        }
        count += (j - i + 1);
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    long long k = 20;

    cout << bruteForce(nums, k) << endl;
    cout << optimalApproach(nums, k) << endl;

    return 0;
}
