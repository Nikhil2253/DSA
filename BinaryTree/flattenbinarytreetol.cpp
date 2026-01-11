#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* flattenBinaryTreeStack(TreeNode* root) {
    if (!root) return nullptr;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* prev = nullptr;

    while (!st.empty()) {
        TreeNode* curr = st.top(); st.pop();
        if (prev) prev->right = curr;
        prev = curr;
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
        curr->left = nullptr;
    }
    return root;
}
// TC: O(n)  SC: O(n)

TreeNode* flattenBinaryTreeOptimal(TreeNode* root, TreeNode*& prev) {
    if (!root) return nullptr;
    flattenBinaryTreeOptimal(root->right, prev);
    flattenBinaryTreeOptimal(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
    return root;
}
// TC: O(n)  SC: O(h)

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    TreeNode* flat1 = flattenBinaryTreeStack(root);
    printFlattened(flat1);

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    TreeNode* prev = nullptr;
    TreeNode* flat2 = flattenBinaryTreeOptimal(root, prev);
    printFlattened(flat2);

    return 0;
}
