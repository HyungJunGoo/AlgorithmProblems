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
    int getDecimalValue(ListNode *head)
    {
        string str = "";
        while (head)
        {
            str += to_string((*head).val);
            head = (*head).next;
        }
        int result = 0;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == '1')
                result += pow(2, str.length() - 1 - i);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    ListNode *head;
}