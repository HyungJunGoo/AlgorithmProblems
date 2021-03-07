/*
Example:

Input: 
citations = [3,0,6,1,5]

Output: 3 

Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>()); 
        int n = citations.size();
        if(n==0)return 0;
        int m = citations[0]; //maximum element
        int max_h = 0;
        for(int i=m; i>=0; i--){
            if(i>n) continue;
            int up=0, down=0;
            for(int j=0; j<n; j++){
                if(citations[j] >= i) up++;
                if(citations[j] <= i) down++;
            }
            if(up>=i && (n-i) <= down){
                if(max_h < i) max_h=i;
            }
        }
        return max_h;
    }
};

int main(){

    vector<int> citations1= {3,0,6,1,5};
    vector<int> citations2 = {1,1,1,1,1};
    vector<int> citations3 = {11,15};
    Solution s;
    cout << s.hIndex(citations2)<< endl;

    return 0;
}