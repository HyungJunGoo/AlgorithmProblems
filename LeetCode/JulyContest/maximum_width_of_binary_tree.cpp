/*
Given a binary tree, write a function to get the maximum width of the given tree. 

The width of a tree is the maximum width among all levels. 

The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes 

(the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
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
    int height = 0;
    map<int, vector<pair<bool, int> > > m; // level, number of elements
    void get_height(TreeNode* root, int level){
        if(!root){
            if(height < level) height = level;
            return;
        }
        get_height(root->left, level+1);
        get_height(root->right, level+1);
    }  
    void traverse(TreeNode* root, int level){
        if(level == height-1) return;
        if(!root) {
            if(m[level].empty()){
                vector<pair<bool, int> > tmp = {make_pair(false, 1)};
                m[level] = tmp;
            }
            else{
                auto it = (m[level].end()-1);
                int n = (*it).second+1;
                m[level].push_back(make_pair(false, n));
            }
            root = new TreeNode();
        }
        if(level == 1){
            vector<pair<bool, int> > tmp = {make_pair(true, 1)};
            m[level] = tmp;
        }
        else{
            if(m[level].empty()){
                vector<pair<bool, int> > tmp = {make_pair(true, 1)};
                m[level] = tmp;
            }
            else {
                auto it = (m[level].end()-1);
                int n = (*it).second+1;
                m[level].push_back(make_pair(true, n));
            }
        }
        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        map<int, vector<pair<bool, int>>>::iterator it;
        int max = 0;
        get_height(root, 1);
        // cout << "height: " << height-1 << endl;
        traverse(root, 1);
        for(it = m.begin(); it != m.end(); it++){
            if( (*it).second.size() >=2 ){
                int left=0 , right=0;
                auto it2 = (*it).second.end()-1;
                for(it2; it2 != (*it).second.begin()-1; it2--){
                    if((*it2).first == false) continue;
                    right = (*it2).second;
                    break;
                }
                it2 = (*it).second.begin();
                for(it2; it2 != (*it).second.end()-1; it2++){
                    if((*it2).first == false) continue;
                    left = (*it2).first;
                    break;
                }
                int length = 0;
                if (right == left) continue;
                else{
                    length = right - left + 1;
                    if(max < length) max = length;
                }        
            }
        }
        return max;
    }
};