# 정수 삼각형
# https://programmers.co.kr/learn/courses/30/lessons/43105
def solution(triangle):
    h = len(triangle)
    dp = [[0 for _ in range(i)] for i in range(1,h+1)]
    dp[0][0] = triangle[0][0]
    for i in range(1, h):
        for j in range(i+1):
            if j == 0:
                dp[i][j] = dp[i-1][j] + triangle[i][j]
            elif j == i:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
    
    return max(dp[h-1])