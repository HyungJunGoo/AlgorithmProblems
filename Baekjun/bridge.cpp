#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int> > dp(31, vector<int>(31));
    for(int i = 1; i < 31; i++)
        dp[1][i] = i;
    for(int i = 2; i < 31; i++){
        for(int j=i; j < 31; j++){
            if(i == j) dp[i][j] =1;
            else{
                for(int k=j-1; k>=1; k--){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }
    int num;
    cin >> num;
    vector<int> ans;
    for(int i = 0; i < num; i++){
        int N, M;
        cin >> N >> M;
        ans.push_back(dp[N][M]);
    }
    for(auto a: ans)
        cout << a << endl;
    return 0;
}