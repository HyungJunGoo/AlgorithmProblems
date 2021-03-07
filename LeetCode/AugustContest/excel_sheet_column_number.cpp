/*
Example 1:

    Input: "A"
    Output: 1

Example 2:

    Input: "AB"
    Output: 28
    => 26*1 + 2
Example 3:

    Input: "ZY"
    Output: 701
    => 26*26 + 25

    "ZZ" => 26*26 + 26 = 702
    "AAA" => 26^2*1 + 26*1 + 1 = 703
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int l = s.length();
        int n =0;
        int res =0;
        for(int i=l-1; i>=0; i--){
            int c = s[i] - 64;
            res+= pow(26,n)*c;
            n++;
        }
        return res;
    }
};

int main()
{
    string str = "FXSHRXW";
    Solution s;
    cout << s.titleToNumber(str) << endl;
    return 0;
}