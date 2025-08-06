#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            // Only collision happens if asteroid is negative and top is positive
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (st.top() < -asteroid) {
                    st.pop(); // top explodes
                    continue;
                } else if (st.top() == -asteroid) {
                    st.pop(); // both explode
                }
                destroyed = true;
                break;
            }

            if (!destroyed)
                st.push(asteroid);
        }

        // Build result from stack
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

// Boilerplate
int main() {
    Solution sol;
    vector<int> asteroids = {7, 90, -5}; // Example
    vector<int> result = sol.asteroidCollision(asteroids);

    for (int a : result) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
