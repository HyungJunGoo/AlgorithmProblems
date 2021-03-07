#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = s.length();
        string _s = "";
        string rev_s = "";
        for (int i = 0; i < l; i++)
        {
            int _c = s[i];
            if ((_c <= 122 && _c >= 97) || (_c <= 90 && _c >= 65) || (_c <= 57 && _c >= 48))
            {
                char c;
                if (_c <= 90 && _c >= 65)
                {
                    _c += 32;
                    c = _c;
                    _s += c;
                }
                else
                {
                    c = _c;
                    _s += c;
                }
            }
            else
                continue;
        }
        for (int i = l - 1; i >= 0; i--)
        {
            int _c = s[i];
            if ((_c <= 122 && _c >= 97) || (_c <= 90 && _c >= 65) || (_c <= 57 && _c >= 48))
            {
                char c;
                if (_c <= 90 && _c >= 65)
                {
                    _c += 32;
                    c = _c;
                    rev_s += c;
                }
                else
                {
                    c = _c;
                    rev_s += c;
                }
            }
            else
                continue;
        }
        cout << rev_s << endl;
        cout << _s << endl;
        if (rev_s == _s)
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "madam";
    Solution a;
    if (a.isPalindrome(s) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}