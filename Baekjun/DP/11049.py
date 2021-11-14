# https://www.acmicpc.net/problem/11049

import sys

input = lambda: sys.stdin.readline()


def solution(N, arr):

    dp = [[0 for _ in range(N)] for _ in range(N)]

    def get_min_val(i, j):
        if i == j:
            return 0
        if i + 1 == j:
            return arr[i][0] * arr[j][0] * arr[j][1]
        if dp[i][j] != 0:
            return dp[i][j]
        else:
            dp[i][j] = sys.maxsize
        for m in range(i, j):
            dp[i][j] = min(
                dp[i][j],
                get_min_val(i, m)
                + get_min_val(m + 1, j)
                + arr[i][0] * arr[m][1] * arr[j][1],
            )
        return dp[i][j]

    return get_min_val(0, N - 1)


if __name__ == "__main__":
    N = int(input().rstrip())
    arr = [list(map(int, (input().split()))) for _ in range(N)]

    print(solution(N, arr))

    # Test
    N = 3
    arr = [[5, 3], [3, 2], [2, 6]]
    assert solution(N, arr) == 90

