from collections import deque
import sys

input = lambda: sys.stdin.readline()


def solution(N, L, A):
    D = [0 for _ in range(N)]
    d = deque()
    for i in range(N):
        while d and d[0][0] <= i - L:
            d.popleft()
        while d and d[-1][1] > A[i]:
            d.pop()
        d.append([i, A[i]])
        D[i] = d[0][1]

    return D


if __name__ == "__main__":

    N, L = map(int, input().split())
    A = list(map(int, input().split()))
    print(*solution(N, L, A))

