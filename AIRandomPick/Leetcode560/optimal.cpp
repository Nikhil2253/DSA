class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixMap;
        prefixMap[0] = 1;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum+=nums[i];

            if(prefixMap.count(sum-k)){
                count+= prefixMap[sum-k];
            }

            prefixMap[sum]++;
        }

        return count;
    }
};
