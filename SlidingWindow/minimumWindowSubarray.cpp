#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

string bruteForce(string s, string t){
    int n = s.length(), m = t.length();
    if(m > n) return "";
    string ans = "";
    int best = INT_MAX;

    unordered_map<char,int> req;
    for(char c: t) req[c]++;

    for(int i=0;i<n;i++){
        unordered_map<char,int> mp = req;
        int count = m;
        for(int j=i;j<n;j++){
            if(mp[s[j]] > 0) count--;
            mp[s[j]]--;
            if(count == 0){
                if(j-i+1 < best){
                    best = j-i+1;
                    ans = s.substr(i, best);
                }
                break;
            }
        }
    }
    return ans;
}

string optimalApproach(string s, string t){
    int n = s.length();
    int requiredCount = t.length();
    if(requiredCount > n) return "";
    
    unordered_map<char,int> mp;
    for(char &ch : t) mp[ch]++;

    int i=0, j=0;
    int windowSize = INT_MAX;
    int start_i = 0;

    while(j < n){
        char ch = s[j];
        if(mp[ch] > 0) requiredCount--;
        mp[ch]--;

        while(requiredCount == 0){
            if(windowSize > j - i + 1){
                windowSize = j - i + 1;
                start_i = i;
            }
            mp[s[i]]++;
            if(mp[s[i]] > 0) requiredCount++;
            i++;
        }
        j++;
    }

    return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << bruteForce(s, t) << endl;
    cout << optimalApproach(s, t) << endl;
    return 0;
}
