# 11066 파일 합치기

import sys
input = lambda: sys.stdin.readline()

def solution(costs):
    n = len(costs)
    sum = [costs[0]]
    for i in range(1,n):
        sum.append(sum[i-1]+costs[i])
    dp = [[0 for _ in range(n)] for _ in range(n)]
    dp[0][1] = sum[1]
    for i in range(1,n-1):
        dp[i][i+1] = sum[i+1] - sum[i-1]
    
    for i in range(2,n): #간격 크기 1, 2, 3
        for j in range(n-i): # 시작 위치  0,1,2..
            dp[j][j+i] = sys.maxsize
            for k in range(j, j+i): # 중간점
                dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i])
            if j == 0:
                dp[j][j+i] += sum[j+i]
            else:
                dp[j][j+i] += sum[j+i] - sum[j-1]
    return dp[0][n-1]

t = int(input())
while t > 0:
    k = int(input())
    costs = list(map(int, input().split()))
    print(solution(costs))
    t-=1