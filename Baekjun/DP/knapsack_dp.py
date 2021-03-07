def knapsack_dp(W, wt, val, n):
    dp = []
    for i in range(n+1):
        row_list = []
        for j in range(W+1):
            row_list.append(0)
        dp.append(row_list)
    # dp[i][j] : 배낭의 용량이 j 일 때, i번 물건까지 담을 수 있는 경우의 최대 케이스
    for i in range(1, n+1):
        for j in range(1, W+1):
            if wt[i-1] > j: # 물건 i 의 무게가 배낭의 용량 j를 초과
                dp[i][j] = dp[i-1][j]
            else : # 물건 i의 무게를 배낭에 담을지 담지 말지 비교
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1])
    print(dp[n][W])
    return dp[n][W]

n, W = input().split()
n = int(n)
W = int(W)
wt = list()
val = list()
for i in range(int(n)):
    w, v = input().split()
    wt.append(int(w))
    val.append(int(v))
knapsack_dp(W, wt, val, n)
