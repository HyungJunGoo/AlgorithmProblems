#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    int y;
    int val;
    Node* left;
    Node* right;

    Node(int x, int y, int val){
        this->x = x;
        this->y = y;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool cmp(Node* a, Node* b){
    return a->y > b->y;
}

void add_node(Node* parent, Node* child){
    if(parent->x < child->x){ //Right side
        if(parent->right == nullptr){
            parent->right = child;
        }
        else{
            add_node(parent->right, child);
        }
    }
    else if(parent->x > child->x){ //Left side
        if(parent->left == nullptr){
            parent->left = child;
        }
        else{
            add_node(parent->left, child);
        }
    }
    return;
}

void preorder_traverse(vector<int> & preorder, Node* node){
    if(node==nullptr) return;
    preorder.push_back(node->val);
    preorder_traverse(preorder, node->left);
    preorder_traverse(preorder, node->right);
}
void postorder_traverse(vector<int> & postorder, Node* node){
    if(node==nullptr) return;
    postorder_traverse(postorder, node->left);
    postorder_traverse(postorder, node->right);
    postorder.push_back(node->val);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> preorder = {};
    vector<int> postorder = {};
    vector<Node*> Node_List (nodeinfo.size());
    // make node from node info
    for(int i =0; i<nodeinfo.size(); i++){
        Node_List[i] = new Node(nodeinfo[i][0], nodeinfo[i][1], i+1);
    }
    // cout << Node_List[1]->val << endl;

    // Sort Node_List by y order 
    sort(Node_List.begin(), Node_List.end(), cmp);
    
    // Make Tree
    for(int i=1; i<Node_List.size(); i++){
        add_node(Node_List[0], Node_List[i]);
    }
    
    // Preorder
    preorder_traverse(preorder, Node_List[0]);
    for(auto node : preorder)
        cout << node << " ";
    cout << endl;
    // Postorder
    postorder_traverse(postorder, Node_List[0]);
    for(auto node : postorder)
        cout << node << " ";
    // answer
    // answer.push_back(preorder);
    // answer.push_back(postorder);
    return answer;
}