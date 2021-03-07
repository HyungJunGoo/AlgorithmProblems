#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    TreeNode* util(vector<int>& inorder, vector<int>& postorder, int s_i, int e_i, int s_p, int e_p){
        if(s_p > e_p || s_i >e_i) return nullptr;
        TreeNode* node = new TreeNode(postorder[e_p]);
        int pivot = s_i;
        while(node->val != inorder[pivot]) pivot++;
        node->left = util(inorder, postorder, s_i, pivot-1, s_p, s_p + pivot - s_i - 1);
        node->right = util(inorder, postorder, pivot+1, e_i, s_p+pivot-s_i, e_p-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        int n = inorder.size();
        TreeNode* result = util(inorder, postorder, 0, n-1, 0, n-1);
        return result;
    }
};

int main()
{
    
    return 0;
}