#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution{
public:
    int largestrectangle(vector<int> arr){
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int height = arr[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, height * (right - left - 1));
            }
            st.push(i);
        }

        // Process remaining elements in stack
        while(!st.empty()){
            int height = arr[st.top()];
            st.pop();
            int right = n;
            int left = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, height * (right - left - 1));
        }

        return maxArea;
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << sol.largestrectangle(heights) << endl;
    return 0;
}
