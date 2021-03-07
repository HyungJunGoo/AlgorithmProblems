#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int n;
    map<int, int> inorder_m;
    map<int, int> postorder_m;
    TreeNode* util(int begin, int end, vector<int>& inorder, vector<int>& postorder){
        
        TreeNode* node;
        if( (end-begin+1) % 2 == 1){ // odd number
            int mid; 
            if((end-begin) != 0)
                mid = begin + (end-begin)/2;
            else mid = begin;
            node = new TreeNode(inorder[mid]);
            if(begin <= mid-1)
                node->left = util(begin, mid-1, inorder, postorder);
            if(mid+1 <= end)
                node->right = util(mid+1, end, inorder, postorder);
        }
        else if( (end-begin+1) % 2 == 0){
            int mid = begin + (end-begin)/2;
            if((inorder_m[inorder[mid]] > inorder_m[inorder[mid+1]] && postorder_m[inorder[mid]] > postorder_m[inorder[mid+1]]) || 
                (inorder_m[inorder[mid]] < inorder_m[inorder[mid+1]] && postorder_m[inorder[mid]] < postorder_m[inorder[mid+1]])){
                node = new TreeNode(inorder[mid+1]);
                if(begin <= mid)
                    node->left = util(begin, mid, inorder, postorder);
                if(mid+2 <= end)
                    node->right = util(mid+2, end, inorder, postorder);
            }
            else {
                node = new TreeNode(inorder[mid]);
                if(begin <= mid-1)
                    node->left = util(begin, mid-1, inorder, postorder);
                if(mid+1 <= end)
                    node->right = util(mid+1, end, inorder, postorder);
            }
        }
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size(); // number of nodes
        if(n == 0){
            return NULL;
        }
        for(int i=0; i<n; i++){
            inorder_m[inorder[i]] = i;
            postorder_m[postorder[i]] = i;
        }
        TreeNode* root = new TreeNode(postorder[n-1]);
        int v_root = postorder[n-1]; // root node's value
        int position;
        for(int i=0; i<n; i++){
            if(inorder[i] == v_root){
                position = i;
                break;
            }
        }
        if(0<=position-1)
            root->left = util(0, position - 1, inorder, postorder);
        if(position+1 <= n-1)
            root->right = util(position+1, n-1, inorder, postorder);
        
        return root;
    }
};

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution s;
    TreeNode* result = s.buildTree(inorder, postorder);

    return 0;
}