#include <bits/stdc++.h>
using namespace std;

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
    void traverse(TreeNode* root, int num, int& sum){
        if(num == 0 & root->left == nullptr && root->right == nullptr){
            sum += root->val;
            return;
        }
        else if (num == 1 && root->left == nullptr && root->right == nullptr)
            return;
        if(root->left)
            traverse(root->left, 0, sum);
        if(root->right)
            traverse(root->right, 1, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root)
            traverse(root, 1, sum);
        return sum;
    }
};

int main()
{

    
    return 0;
}