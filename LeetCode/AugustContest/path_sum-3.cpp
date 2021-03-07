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
    int cnt = 0;
    void traverse(TreeNode* root, deque<int>& cur, int& sum){
        if(!root) return;
        for(int i=0; i<cur.size(); i++)
            cur[i] += root->val;
        cur.push_back(root->val);
        for(auto n : cur){
            if( n == sum) cnt++;
        }
        traverse(root->left, cur, sum);

        traverse(root->right, cur, sum);
        for(int i=0; i<cur.size(); i++)
            cur[i] -= root->val;
        cur.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        deque<int> cur;
        traverse(root, cur, sum);
        return cnt;
    }
};