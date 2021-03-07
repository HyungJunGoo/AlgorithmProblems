/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
Example
    Input: a = "11", b = "1"
    Output: "100"

    Input: a = "1010", b = "1011"
    Output: "10101"
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int l_a = a.length();
        int l_b = b.length();
        int len = l_a;
        if(l_a > l_b){
            int diff = l_a - l_b;
            string ext = "";
            for(int i=0; i<diff; i++)
                ext += '0';
            b = ext + b;
        }
        else if(l_a < l_b){
            len = l_b;
            int diff = l_b - l_a;
            string ext = "";
            for(int i=0; i<diff; i++)
                ext += '0';
            a = ext + a;
        }
        bool carry = false;
        string result = "";
        for(int i=len-1; i>=0; i--){
            if(a[i] == '1' && b[i] == '1'){
                if(carry){
                    result = '1' + result;
                    continue;
                }
                else{
                    carry = true;
                    result = '0' + result;
                }
            }
            else if (a[i] == '1' || b[i] == '1'){
                if (carry){
                    result = '0' + result;
                }
                else{
                    carry = false;
                    result = '1' + result;
                }
            }
            else{
                if(carry){
                    result = '1' + result;
                    carry = false;
                }
                else
                    result = '0' + result;
            }
        }
        if(carry)
            result = '1' + result;

        return result;
    }
};
int main()
{
    string a = "1010";
    string b = "1011";
    Solution s;
    cout << s.addBinary(a , b) << endl;
    return 0;
}