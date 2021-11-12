# https://www.acmicpc.net/problem/2079

import sys

sys.setrecursionlimit(1000000)
# input = lambda: sys.stdin.readline()


def solution(s):
    n = len(s)
    dp = [[0 for _ in range(n)] for _ in range(n)]
    dp2 = [0 for _ in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(i, n):
            if i == j:
                dp[i][j] = 1
            elif i + 1 == j and s[i] == s[j]:
                dp[i][j] = 1
            elif dp[i + 1][j - 1] == 1 and s[i] == s[j]:
                dp[i][j] = 1

    def get_minimum_number(x):
        if x < 0:
            return 0
        if dp2[x] != 0:
            return dp2[x]
        dp2[x] = 200000
        for i in range(x, -1, -1):
            if dp[i][x] == 1:
                dp2[x] = min(dp2[x], 1 + get_minimum_number(i - 1))
        return dp2[x]

    result = get_minimum_number(n - 1)
    return result


if __name__ == "__main__":
    s = input()
    print(solution(s))

    # assert solution("aaabbbbabab") == 3

    # assert solution("anaban") == 2
    # assert solution("abaccbcb") == 3
    # assert solution("anavolimilana") == 5

