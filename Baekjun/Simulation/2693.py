# 2693 < N번째 큰수>
#https://www.acmicpc.net/problem/2693

import sys

input = lambda: sys.stdin.readline()

def solution():
    arr = list(map(int, input().split()))
    arr = sorted(arr,reverse=True)
    print(arr[2])
    return

t=int(input())
while t>0:
    solution()
    t-=1