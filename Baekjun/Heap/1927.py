# 1927

import sys
from collections import _heapq as hq

input = lambda: sys.stdin.readline()

def solution():
    h = []

    N = int(input())
    for _ in range(N):
        n = int(input())

        if n == 0:
            if len(h) == 0:
                print(0)
            else:
                print(h[0])
                hq.heappop(h)
        else:
            hq.heappush(h,n)
    return


if __name__ == "__main__":

    solution()