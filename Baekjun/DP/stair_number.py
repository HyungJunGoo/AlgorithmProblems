#1562번 계단 수
import sys

def dp(N):
    MOD = 1000000000
    visited = 1<<10
    dp = [[[0 for _ in range(1<<10)] for _ in range(11)] for _ in range(101)]

    for i in range(1,10):
        dp[1][i][1<<i] = 1
    for i in range(2, N+1):
        for j in range(10):
            for k in range(1<<10):
                bit_mask = k|(1<<j)
                if j == 0:
                    dp[i][j][bit_mask] = (dp[i][j][bit_mask] + dp[i-1][j+1][k])%MOD
                elif j==9:
                    dp[i][j][bit_mask] = (dp[i][j][bit_mask] + dp[i-1][j-1][k])%MOD
                else:
                    dp[i][j][bit_mask] = (dp[i][j][bit_mask] + dp[i-1][j-1][k] + dp[i-1][j+1][k])%MOD
    answer = 0
    for i in range(10):
        answer = (answer + dp[N][i][(1<<10)-1])%MOD
    return answer

def main():

    N = int(sys.stdin.readline())
    print(dp(N))
    return

if __name__ == "__main__":
    main()
