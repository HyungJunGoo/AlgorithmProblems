# https://www.acmicpc.net/problem/1727
import sys


def solution(n, m, male, female):
    dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

    male, female = sorted(male), sorted(female)

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = dp[i - 1][j - 1] + abs(male[i - 1] - female[j - 1])
            if i < j:
                dp[i][j] = min(dp[i][j], dp[i][j - 1])
            if i > j:
                dp[i][j] = min(dp[i][j], dp[i - 1][j])
    return dp[n][m]


if __name__ == "__main__":
    input = lambda: sys.stdin.readline()
    n, m = map(int, input().split())

    male = list(map(int, input().split()))
    female = list(map(int, input().split()))
    print(solution(n, m, male, female))
