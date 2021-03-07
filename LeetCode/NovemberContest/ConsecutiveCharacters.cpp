#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxPower(string s)
    {
        int l = s.length();
        int maximum = 0;
        int count = 0;
        char lastCharacter;

        for (int i = 0; i < l; i++)
        {
            if (i == 0)
            {
                lastCharacter = s[i];
                count++;
                continue;
            }
            if (s[i] != lastCharacter)
            {
                if (maximum < count)
                    maximum = count;
                count = 1;
                lastCharacter = s[i];
            }
            else
            {
                count++;
            }
        }
        if (maximum < count)
            maximum = count;

        return maximum;
    }
};

int main()
{
    Solution solution;
    int a = solution.maxPower("hooraaaaaaaaaaay");
    cout << a << endl;
    return 0;
}