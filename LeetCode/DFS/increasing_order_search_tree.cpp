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
    vector<int> in_order;

public:
    void utilBST(TreeNode *root)
    {
        if (!root)
            return;
        utilBST(root->left);
        in_order.push_back(root->val);
        utilBST(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        utilBST(root);
        TreeNode *result = new TreeNode(in_order[0]);
        TreeNode *answer = result;
        for (int i = 1; i < in_order.size(); i++)
        {
            result->right = new TreeNode(in_order[i]);
            result = result->right;
        }

        return answer;
    }
};

int main()
{
    TreeNode *test = new TreeNode(1);
    TreeNode *l_test = new TreeNode(2);
    TreeNode *r_test = new TreeNode(3);
    test->left = l_test;
    test->right = r_test;
    Solution s;
    TreeNode *answer;
    answer = s.increasingBST(test);
    cout << answer->right->right->val << endl;

    return 0;
}