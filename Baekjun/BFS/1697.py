# 숨바꼭질
from collections import deque
import sys
N, K = map(int, input().split())

def solution(N,K):
    if N >= K:
        return N-K
    visit = [0 for _ in range(10**6)]
    q = deque()
    q.append(N+1)
    q.append(N-1)
    q.append(N*2)
    visit[N] = 1
    time = 1
    while 1:
        tmp_q = deque()
        while len(q):
            x = q.popleft()
            if x == K:
                return time
            visit[x] = 1
            if x <= K and visit[x+1]==0 and (x+1 > 0 and x<=100000):
                
                tmp_q.append(x+1)
            if visit[x-1]==0 and x-1 > 0:
                tmp_q.append(x-1)
            if x<=K and (x*2 > 0 and x<=100000) and visit[x*2]==0:
                tmp_q.append(x*2)
        q = tmp_q
        time += 1
    return time
print(solution(N,K))