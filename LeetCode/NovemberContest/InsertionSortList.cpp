#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        vector<int> numList;
        while (head)
        {
            numList.push_back((*head).val);
            head = (*head).next;
        }

        int numListSize = numList.size();
        if (numListSize == 1)
            return head;
        int lastval = 0;
        for (int i = 0; i < numListSize; i++)
        {
            if (i == 0)
            {
                lastval = numList[i];
                continue;
            }
            int val = numList[i];
            if (val < lastval)
            {
                for (int j = 0; j < i; j++)
                {
                    if (numList[j] > val)
                    {
                        numList.insert(numList.begin() + j, val);
                        break;
                    }
                }
                numList.erase(numList.begin() + i + 1);
            }
            lastval = numList[i];
        }
        vector<ListNode *> ListNodeList;
        for (int n : numList)
        {
            ListNode *tmpListNode = new ListNode(n);
            ListNodeList.push_back(tmpListNode);
        }
        for (int i = 0; i < numListSize; i++)
        {
            if (i == numListSize - 1)
            {
                (*ListNodeList[i]).next = nullptr;
                continue;
            }
            (*ListNodeList[i]).next = ListNodeList[i + 1];
        }
        return *ListNodeList.begin();
    }
};