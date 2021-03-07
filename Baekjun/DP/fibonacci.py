import sys

def main():

    N = int(sys.stdin.readline())
    dp = [[0,0] for _ in range(41)]
    dp[0][0] += 1
    dp[1][1] += 1
    for i in range(2, 41):
        dp[i][0] = dp[i-1][0] + dp[i-2][0]
        dp[i][1] = dp[i-1][1] + dp[i-2][1]
    for _ in range(N):
        x = int(sys.stdin.readline())
        print(dp[x][0], end=" ")
        print(dp[x][1])
    return

if __name__ == "__main__":
    main()