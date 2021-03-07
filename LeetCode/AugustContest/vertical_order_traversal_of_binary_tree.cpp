/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, 

we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.


*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode * right) : val(x), left(left), right(right) {}
};

bool mysort(pair<int, int> &a, pair<int, int> &b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> nodes;

    void traverse(TreeNode* root, int x_o, int y_o){
        if(!root)
            return ;
        if(nodes[x_o].empty()){
            vector<pair<int,int>> tmp;
            tmp.push_back(make_pair(y_o,root->val));
            nodes[x_o]=tmp;
        }
        else{
            nodes[x_o].push_back(make_pair(y_o,root->val));
        }
        traverse(root->left, x_o-1, y_o-1);
        traverse(root->right, x_o+1, y_o-1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 0, 0);
        int n = nodes.size();
        for(int i = 1-n; i<n; i++){
            if(nodes[i].empty())
                continue;
            sort(nodes[i].begin(), nodes[i].end(), mysort);
            vector<int> tmp;
            for(int j=0; j<nodes[i].size(); j++)
                tmp.push_back(nodes[i][j].second);
            res.push_back(tmp);
        }
        return res;
    }
};

int main()
{

}