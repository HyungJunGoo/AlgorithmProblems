/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 

(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution {
public:
    map<int, deque<int> > node_list;
    void bfs_traverse(TreeNode* root, int l, bool direction){
        if(!root) return;
        if(direction == true){ // from left to right
            node_list[l].push_back(root->val);
        }
        else{ // from right to left
            node_list[l].push_front(root->val);
        }
        bfs_traverse(root->left, l+1, !direction);
        bfs_traverse(root->right, l+1, !direction);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs_traverse(root, 1, true);
        map<int, deque<int> >::iterator itr;
        vector<vector<int> > result;
        for(itr = node_list.begin(); itr != node_list.end(); itr++){
            vector<int> tmp;
            for(auto i : (*itr).second ){
                tmp.push_back(i);
            }
            result.push_back(tmp);
        }
        return result;
    }
};