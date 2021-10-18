# 1 2 2 3 3 3 4 4 4 4 5
import math, sys

input = lambda : sys.stdin.readline()

a,b = map(int,input().split())
n=0
i = 1
arr = [0 for _ in range(1001)]
count = 0
for idx in range(1,1001):
    if count == i:
        count = 0
        i+=1
    arr[idx] = arr[idx-1] + i
    count += 1
n = arr[b] - arr[a-1]
print(n)