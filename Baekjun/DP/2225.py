# https://www.acmicpc.net/problem/2225

import sys

input = lambda: sys.stdin.readline()
MOD = int(1e9)


def solution(N, K):

    dp = [[0 for _ in range(N + 1)] for _ in range(K)]
    for i in range(K):
        for j in range(N + 1):
            if i == 0:
                dp[i][j] = 1
            else:
                for p in range(j + 1):
                    dp[i][j] += dp[i - 1][p]
                    dp[i][j] %= MOD

    return dp[K - 1][N]


if __name__ == "__main__":

    N, K = map(int, input().split())
    print(solution(N, K))
