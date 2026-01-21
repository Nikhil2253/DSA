class Solution {
public:
    bool helperFunction(int n, int k, vector<int> &arr){
        vector<bool> prev(k+1, false), curr(k+1, false);
        prev[0] = true;

        if(arr[0] <= k)
            prev[arr[0]] = true;

        for(int ind = 1; ind < n; ind++){
            curr.assign(k+1, false);
            curr[0] = true;

            for(int target = 1; target <= k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target)
                    take = prev[target - arr[ind]];

                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;
        return helperFunction(nums.size(), sum/2, nums);
    }
};
