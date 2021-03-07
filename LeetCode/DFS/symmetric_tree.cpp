#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool BFS(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left && right || left && !right)
            return false;

        if (left->val == right->val)
        {
            if (BFS(left->left, right->right) && BFS(left->right, right->left))
                return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        if ((!root->left && root->right) || (root->left && !root->right))
            return false;
        if (!root->left && !root->right)
            return true;

        if (root->left->val == root->right->val)
        {
            if (BFS(root->left, root->right))
                return true;
        }
        return false;
    }
};
