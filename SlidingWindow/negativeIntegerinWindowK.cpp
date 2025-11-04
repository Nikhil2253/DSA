#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> optimalApproach(vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;
    queue<int> q;

    int i = 0, j = 0;

    while(j < n) {
        if(arr[j] < 0) q.push(arr[j]);

        if(j - i + 1 < k) {
            j++;
        } 
        else {
            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);

            if(!q.empty() && arr[i] == q.front()) q.pop();

            i++;
            j++;
        }
    }
    return ans;
}

vector<int> bruteForce(vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i <= n - k; i++){
        int firstNeg = 0;
        for(int j = i; j < i + k; j++){
            if(arr[j] < 0){
                firstNeg = arr[j];
                break;
            }
        }
        ans.push_back(firstNeg);
    }
    return ans;
}

int main(){
    vector<int> arr = {12, -1, -7, 8, 15, 30, 16, -28};
    int k = 3;

    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\nWindow Size = " << k << endl;

    vector<int> brute = bruteForce(arr, k);
    vector<int> optimal = optimalApproach(arr, k);

    cout << "\nBrute Force Output: ";
    for(int x : brute) cout << x << " ";

    cout << "\nOptimal Output:     ";
    for(int x : optimal) cout << x << " ";

    cout << endl;
    return 0;
}
