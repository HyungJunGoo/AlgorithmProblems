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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string n1 = "";
        string n2 = "";

        while (l1)
        {
            n1.append(to_string((*l1).val));
            l1 = (*l1).next;
        }
        while (l2)
        {
            n2.append(to_string((*l2).val));
            l2 = (*l2).next;
        }
        // int result = stoi(n1) + stoi(n2); // range over

        int len_n1 = n1.length();
        int len_n2 = n2.length();
        int itr1 = len_n1 - 1, itr2 = len_n2 - 1;
        while (len_n1 > 0 && len_n2 > 0)
        {
            int sum = n1[itr1] - '0' + n2[itr2] - '0';
            bool carry = false;
            if (sum >= 10)
            {
                carry = true;
                sum -= 10;
            }

            if (len_n1 > len_n2)
            {
                n1[itr1] = char(sum);
                if (carry)
                {
                    if (itr1 == 0)
                    {
                        string tmp = "1";
                        n1 = tmp.append(n1);
                    }
                    else
                    {
                        int n = n1[itr1 - 1] - '0' + 1;
                        n1[itr1 - 1] = char(n);
                    }
                }
            }
            else
            {
                n2[itr2] = char(sum);
                if (carry)
                {
                    if (itr2 == 0)
                    {
                        string tmp = "1";
                        n2 = tmp.append(n2);
                    }
                    else
                    {
                        int n = n2[itr2 - 1] - '0' + 1;
                        n2[itr2 - 1] = char(n);
                    }
                }
            }
            itr1--;
            itr2--;
            if (carry)
                !carry;
        }
        int result = 0;
        if (len_n1 > len_n2)
            result += stoi(n1);
        else
            result += stoi(n2);

        string str_result = to_string(result);
        vector<ListNode *> vec_result;
        for (int i = 0; i < str_result.length(); i++)
        {
            ListNode *tmp_ListNode = new ListNode(str_result[i] - '0');
            vec_result.push_back(tmp_ListNode);
        }
        for (int i = 0; i < vec_result.size(); i++)
        {
            if (i == vec_result.size() - 1)
            {
                (*vec_result[i]).next == nullptr;
                continue;
            }
            (*vec_result[i]).next = vec_result[i + 1];
        }
        return *vec_result.begin();
    }
};