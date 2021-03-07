/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
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
    map<int, vector<int> > numbers_by_level;
    int last_level = 0;
    void recursion(vector<int>& tmp, TreeNode* root, int lev){
        if(!root) {
            return;
        }
        else{
            if(last_level < lev) last_level = lev;
            if(numbers_by_level[lev].empty()){
                vector<int> tmp;
                tmp.push_back(root->val);
                numbers_by_level[lev] = tmp;
            }
            else{
                numbers_by_level[lev].push_back(root->val);
            }
        }
        recursion(tmp, root->left, lev+1);
        recursion(tmp, root->right, lev+1);
    }  
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> tmp;
        vector<vector<int> > result;
        recursion(tmp, root, 1);
        for(int i=last_level; i>=1; i--){
            result.push_back(numbers_by_level[i]);
        }
        return result;
    }
};