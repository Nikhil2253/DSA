#include <iostream>
using namespace std;

class Solution {
public:
    // Function to compute mid^n safely (stops early if > m)
    long long power(long long mid, int n, int m) {
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= mid;
            if (ans > m) return ans; // avoid overflow & extra calc
        }
        return ans;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long val = power(mid, n, m);

            if (val == m) return mid;      // exact root found
            else if (val < m) low = mid + 1; 
            else high = mid - 1;
        }

        return -1; // no integer nth root exists
    }
};

int main() {
    Solution s;
    cout << s.nthRoot(2, 16) << endl;  // 4
    cout << s.nthRoot(3, 27) << endl;  // 3
    cout << s.nthRoot(3, 15) << endl;  // -1 (not a perfect cube)
    cout << s.nthRoot(4, 81) << endl;  // 3
    cout << s.nthRoot(5, 243) << endl; // 3
    return 0;
}
