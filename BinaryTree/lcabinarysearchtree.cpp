#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insertBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main()
{
    TreeNode *root = NULL;

    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        root = insertBST(root, values[i]);
    }

    int p = 2, q = 8;

    TreeNode *lca = lowestCommonAncestor(root, p, q);

    if (lca)
        cout << lca->val << endl;

    return 0;
}
