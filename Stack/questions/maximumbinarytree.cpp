#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr; // ✅ base case

        int maxIndex = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = build(nums, start, maxIndex - 1);   // ✅ correct range
        root->right = build(nums, maxIndex + 1, end);    // ✅ correct range

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = sol.constructMaximumBinaryTree(nums);

    // simple check: print root value
    cout << "Root value: " << root->val << endl; // should print 6
    return 0;
}
