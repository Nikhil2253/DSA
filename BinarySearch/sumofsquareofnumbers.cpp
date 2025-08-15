#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = (long long) sqrt(c); // Largest possible square root

        // Time Complexity: O(sqrt(c)) — at most b steps
        // Space Complexity: O(1) — no extra space
        while (a <= b) {
            long long sum = a * a + b * b;

            if (sum == c) {
                return true; // Found integers a and b such that a² + b² = c
            } 
            else if (sum < c) {
                a++; // Need a bigger sum
            } 
            else {
                b--; // Need a smaller sum
            }
        }
        return false; // No such pair found
    }
};

int main() {
    Solution sol;

    int c1 = 5;  // 1² + 2² = 5 → should return true
    int c2 = 3;  // No two squares add to 3 → should return false

    cout << "c = " << c1 
         << (sol.judgeSquareSum(c1) ? " true" : " false") << endl;

    cout << "c = " << c2  
         << (sol.judgeSquareSum(c2) ? " true" : " false") << endl;

    return 0;
}
