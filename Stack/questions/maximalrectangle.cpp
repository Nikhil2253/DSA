#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Helper function to compute Largest Rectangle in Histogram
    // Time: O(m), Space: O(m)
    int largestRectangle(vector<int> &arr)
    {
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            // Maintain stack in increasing order of heights
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                int height = arr[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, height * (right - left - 1));
            }
            st.push(i);
        }

        // Process remaining elements in stack
        while (!st.empty())
        {
            int height = arr[st.top()];
            st.pop();
            int right = n;
            int left = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, height * (right - left - 1));
        }

        return maxArea;
    }

    // Main function to compute maximal rectangle in binary matrix
    // TC: O(n * m) where n = rows, m = columns
    // SC: O(m) for heights array
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;

        int n = matrix.size();    // rows
        int m = matrix[0].size(); // columns

        // heights[j] stores the histogram height for column j at current row
        vector<int> heights(m, 0);
        int maxArea = 0;

        // Process each row as a histogram
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j] += 1; // Increase height for continuous 1's
                else
                    heights[j] = 0; // Reset height if current cell is '0'
            }

            // For this histogram (row), get the largest rectangle
            maxArea = max(maxArea, largestRectangle(heights));
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    
    cout << sol.maximalRectangle(matrix) << endl; // Expected output: 6
    return 0;
}
