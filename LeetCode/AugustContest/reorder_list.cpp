/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
*/
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    deque<ListNode*> nodes;
    deque<ListNode*> listed_nodes;
    void reorderList(ListNode* head) {
        if(!head) return;
        while(head != nullptr){
            nodes.push_back(head);
            head = head->next;
        }
        int n = nodes.size();
        for(int i=0; i<(n/2); i++){
            listed_nodes.push_back(nodes[i]);
            listed_nodes.push_back(nodes[(n-1)-i]);
        }
        if(n%2==1){
            listed_nodes.push_back(nodes[n/2]);
        }
        for(int i=0; i<n-1; i++){
            listed_nodes[i]->next = listed_nodes[i+1];
        }
        listed_nodes[n-1]->next = nullptr;
        head = listed_nodes[0];
    }
};

int main() 
{
    return 0;
}