/*
    Example
    Input:  00000010100101000001111010011100
    Output: 00111001011110000010100101000000
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string origin = to_string(n);
        reverse(origin.begin(), origin.end());
        uint32_t result = stoll(origin);
        return result;
    }
};

int main()
{
    uint32_t n = 00000010100101000001111010011100;
    Solution s;
    cout << s.reverseBits(n) << endl;
}