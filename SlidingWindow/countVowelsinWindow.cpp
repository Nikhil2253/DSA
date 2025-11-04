#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isVowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int bruteForce(string s, int k){
    int n = s.length();
    int ans = INT_MIN;
    for(int i=0;i<=n-k;i++){
        int count = 0;
        for(int j=i;j<i+k;j++){
            if(isVowel(s[j])) count++;
        }
        ans = max(ans,count);
    }
    return ans;
}

int optimalApproach(string s, int k){
    int n = s.length();
    int count = 0;
    int ans = INT_MIN;
    int i=0,j=0;
    while(j<n){
        if(isVowel(s[j])) count++;
        if(j-i+1==k){
            ans = max(ans,count);
            if(isVowel(s[i])) count--;
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    string s = "nikhil";
    int k = 4;

    int a = bruteForce(s,k);
    int b = optimalApproach(s,k);

    cout << a << endl;
    cout << b << endl;

    return 0;
}
