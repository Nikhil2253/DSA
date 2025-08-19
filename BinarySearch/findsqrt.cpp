#include <iostream>
using namespace std;

class Solution {
public:
    // O(√x) Linear Search
    int linearSqrt(int x) {
        if (x == 0 || x == 1) return x;
        int ans = 1;
        for (long long i = 1; i <= x / 2; i++) {
            if (i * i == x) return i;
            if (i * i < x) ans = i;
            else break;
        }
        return ans;
    }

    // O(log x) Binary Search
    int binarySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long long low = 1, high = x / 2, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;

            if (sq == x) return mid;
            else if (sq < x) {
                ans = mid;       // store floor value
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x1 = 8, x2 = 16, x3 = 1, x4 = 0;

    cout << "x = " << x1 << " -> Linear: " << sol.linearSqrt(x1) 
         << ", Binary: " << sol.binarySqrt(x1) << endl;

    cout << "x = " << x2 << " -> Linear: " << sol.linearSqrt(x2) 
         << ", Binary: " << sol.binarySqrt(x2) << endl;

    cout << "x = " << x3 << " -> Linear: " << sol.linearSqrt(x3) 
         << ", Binary: " << sol.binarySqrt(x3) << endl;

    cout << "x = " << x4 << " -> Linear: " << sol.linearSqrt(x4) 
         << ", Binary: " << sol.binarySqrt(x4) << endl;

    return 0;
}
