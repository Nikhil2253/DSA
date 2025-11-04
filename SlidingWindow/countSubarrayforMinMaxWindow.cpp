#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long bruteForce(vector<int> nums, int minK, int maxK){
    long long count = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int mn = nums[i], mx = nums[i];
        for(int j = i; j < n; j++){
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            if(mn == minK && mx == maxK){
                bool ok = true;
                for(int k = i; k <= j; k++){
                    if(nums[k] < minK || nums[k] > maxK){
                        ok = false;
                        break;
                    }
                }
                if(ok) count++;
            }
        }
    }
    return count;
}

long long optimalApproach(vector<int> nums, int minK, int maxK){
    long long count = 0;
    int lastMin = -1, lastMax = -1, bad = -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < minK || nums[i] > maxK) bad = i;
        if(nums[i] == minK) lastMin = i;
        if(nums[i] == maxK) lastMax = i;
        count += max(0, min(lastMin, lastMax) - bad);
    }
    return count;
}

int main(){
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;

    long long a = bruteForce(nums, minK, maxK);
    long long b = optimalApproach(nums, minK, maxK);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
