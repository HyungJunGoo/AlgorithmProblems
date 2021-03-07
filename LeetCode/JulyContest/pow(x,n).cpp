#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);        
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    return 0;
}