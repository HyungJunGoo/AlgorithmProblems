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
    bool recursive(TreeNode *p, TreeNode *q)
    {
        if (!p && q || p && !q || p->val != q->val)
            return false;
        else if (!p && !q)
            return true;

        if (recursive(p->left, q->left) == false)
            return false;
        if (recursive(p->right, q->right) == false)
            return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (recursive(p, q))
            return true;
        return false;
    }
};
