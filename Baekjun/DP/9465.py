# 9465 <스티커>

import sys

input = lambda: sys.stdin.readline()

def solution(n, numbers):
    d=[[0]*n for _ in range(2)]
    d[0][0]=numbers[0][0]
    d[1][0]=numbers[1][0]
    if n == 1:
        print(max(d[0][0], d[1][0]))
        return
    d[0][1] = numbers[0][1]+d[1][0]
    d[1][1] = numbers[1][1]+d[0][0]
    for i in range(2, n):
        d[0][i] = max(d[1][i-1], max(d[0][i-2], d[1][i-2]))+numbers[0][i]
        d[1][i] = max(d[0][i-1], max(d[0][i-2], d[1][i-2]))+numbers[1][i]
    print(max(d[0][n-1], d[1][n-1]))
    return

if __name__ == "__main__":
    T=int(input())

    for _ in range(T):
        n = int(input())
        numbers=[list(map(int, input().split())) for _ in range(2)]
        solution(n, numbers)