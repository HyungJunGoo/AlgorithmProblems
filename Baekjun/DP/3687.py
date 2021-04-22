# 3687 성냥개비

import sys

input = lambda: sys.stdin.readline()
dp = [0 for _ in range(101)]
dp[2] = 1
dp[3] = 7
dp[4] = 4
dp[5] = 2
dp[6] = 6
dp[7] = 8
dp[8] = 10
num = [0,0,1,7,4,2,0,8,10]
T = int(input())

for i in range(T):
    n = int(input())
    minv, maxv = 0,""
    #maxv
    if n%2 == 0:
        for j in range(n//2):
            maxv += '1'
    else:
        maxv += '7'
        for j in range((n-3)//2):
            maxv += '1'
    #minv
    for j in range(9, n+1):
        dp[j] = sys.maxsize
        for idx in range(2, 8):
            dp[j] = min(dp[j], dp[j-idx]*10+num[idx])
    minv = dp[n]
    print(f"{minv} {maxv}")