# 2357

import sys
import heapq

input = lambda : sys.stdin.readline()

def main():
    N, M = list(map(int, input().split()))
    numbers = [int(input()) for _ in range(N)]

    for _ in range(M):
        a, b = list(map(int, input().split()))
        nums = numbers[a-1: b]
        small = heapq.nsmallest(1, nums)[0]
        large = heapq.nlargest(1, nums)[0]
        print(f"{small} {large}")
    return

if __name__ == "__main__":
    main()