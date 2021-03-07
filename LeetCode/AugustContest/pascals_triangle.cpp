/*
           1
        1     1
    1      2       1
1      3       3        1
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > pascals_triangle(33);
        vector<int> first_row(1); first_row[0] = 1;
        pascals_triangle[0] = first_row;
        if(rowIndex == 0) return first_row;
        vector<int> second_row (2); second_row[0] = second_row[1] = 1;
        pascals_triangle[1] = second_row;
        if(rowIndex == 1) return second_row;
        for(int i = 2; i <=rowIndex; i++){
            vector<int> tmp (i+1);
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i)
                    tmp[j] = 1;
                else{
                    tmp[j] = pascals_triangle[i-1][j-1] + pascals_triangle[i-1][j];
                }
            }
            pascals_triangle[i] = tmp;
        }
        return pascals_triangle[rowIndex];
        
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.getRow(33);
    for(int n : ans){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}