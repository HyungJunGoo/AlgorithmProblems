#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {  
public:
    Node* result;
    vector<Node*> vect;

    void traverse(Node* head){
        if(!head) return;
        vect.push_back(head);
        if(head->child){
            traverse(head->child);
        }
        traverse(head->next);
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;
        vect.push_back(NULL);
        traverse(head);
        Node* result = new Node();
        int sz = vect.size();
        for(int i=1; i<sz-1; i++){
            vect[i]->prev = vect[i-1];
            vect[i]->next = vect[i+1];
            vect[i]->child = nullptr;
        }
        vect[sz-1]->prev = vect[sz-2];
        vect[sz-1]->next = NULL;
        vect[sz-1]->child = NULL;
        return vect[1];
    }
};