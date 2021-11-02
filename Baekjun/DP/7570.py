# https://www.acmicpc.net/problem/7570


import sys

input = lambda: sys.stdin.readline()


def solution(n, nums):
    dp = [0 for _ in range(n + 1)]
    result = 0
    for num in nums:
        dp[num] = dp[num - 1] + 1
        result = max(result, dp[num])
    return n - result


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    print(solution(n, nums))
