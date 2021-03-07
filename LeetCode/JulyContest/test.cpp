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

int main()
{   
    unordered_map<int, int> t;
    t[1] = 3;
    t[2] = 4;
    t.erase(1);
    t.erase(2);
    cout << t.size() << endl;


    return 0;
}