#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / n;   // row index
            int col = mid % n;   // col index

            int val = matrix[row][col];
            if (val == target) {
                return true;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target=20;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in matrix!" << endl;
    }

    return 0;
}
