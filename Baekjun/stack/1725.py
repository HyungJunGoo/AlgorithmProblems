# 1725

import sys
from collections import deque
input=lambda: sys.stdin.readline()
answer = 0
N = int(input())
h = [0 for _ in range(N+2)]
for i in range(1,N+1):
    h[i] += int(input())
s = deque()
s.appendleft(0)
for i in range(1, N+2):
    while len(s) > 0 and h[s[0]] > h[i]:
        check = s[0]
        s.popleft()
        answer = max(answer, h[check]*(i-s[0]-1))
    s.appendleft(i)
print(answer)
sys.exit()