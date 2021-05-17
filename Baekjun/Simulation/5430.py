# 5430
import sys
from collections import deque
input = lambda: sys.stdin.readline()

T = int(input())

for _ in range(T):
    p = input()
    n = int(input())
    arr = input().strip()[1:-1].split(',')
    p = p.replace('RR', '')

    r=0
    s,e = 0,0
    for j in p:
        if j == 'R':
            r+=1
        elif j == 'D':
            if r%2==0:
                s+=1
            else:
                e+=1
    if s+e<=n:
        arr = arr[s:n-e]
        if r%2==1:
            print('['+','.join(arr[::-1])+']')
        else:
            print('['+','.join(arr)+']')
    else:
        print('error')

sys.exit()