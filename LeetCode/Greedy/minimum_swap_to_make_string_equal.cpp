#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int l = s1.length();
        int count = 0;
        // First check if its possible or not
        int cnt_x = 0, cnt_y = 0;
        for (int i = 0; i < l; i++)
        {
            if (s1[i] == 'x')
                cnt_x++;
            else
                cnt_y++;

            if (s2[i] == 'x')
                cnt_x++;
            else
                cnt_y++;
        }
        if (cnt_x % 2 == 1)
            return -1;

        // Compare to strings and get rid of equal char
        string _s1 = "",
               _s2 = "";
        for (int i = 0; i < l; i++)
        {
            if (s1[i] == s2[i])
            {
                continue;
            }
            else
            {
                _s1 += s1[i];
                _s2 += s2[i];
            }
        }

        // while (s1, s2's length > 0)
        while (_s1.length() > 0)
        {
            // iteratively doing same logic

            // logic -> take s1[0] and find nearest different char in s1 then we call it s1[n]
            // swap (s1[n], s2[0]) then we can remove 2 char from both s1, s2
            // renew s1, s2, and count += 1
            int n = 0;
            for (int i = 1; i < _s1.length(); i++)
            {
                if (_s1[0] == _s1[i])
                {
                    n += i;
                    break;
                }
            }

            swap(_s1[n], _s2[0]);
            string t_s1 = "", t_s2 = "";
            for (int i = 0; i < _s1.length(); i++)
            {
                if (_s1[i] == _s2[i])
                {
                    continue;
                }
                else
                {
                    t_s1 += _s1[i];
                    t_s2 += _s2[i];
                }
            }
            _s1 = t_s1;
            _s2 = t_s2;
            count++;
        }

        return count;
    }
};

int main()
{
    string s1 = "xx";
    string s2 = "xy";

    Solution s;
    cout << s.minimumSwap(s1, s2) << endl;
    return 0;
}