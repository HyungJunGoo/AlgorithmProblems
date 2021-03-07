#include <bits/stdc++.h>
using namespace std;

int dp[3000];
int last;
int main()
{
    int n; 
    cin >> n;
    vector<int> arr(n+1);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        arr[i+1] = t;
    }
    last = n - 1;

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-2] + arr[i] , dp[i-3] + arr[i-1] + arr[i]);
    }
    cout << dp[n] << endl;

    return 0;
}