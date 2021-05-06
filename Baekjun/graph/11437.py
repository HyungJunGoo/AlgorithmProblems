# 11437 <LCA>

import sys
from collections import defaultdict
from collections import deque
from copy import copy

input = lambda : sys.stdin.readline()

N = int(input())
g=defaultdict(list)
for _ in range(N-1):
    a,b = list(map(int,input().split()))
    g[a].append(b)
    g[b].append(a)
root = 1
parent = [0 for _ in range(N+1)]
depth = [0 for _ in range(N+1)]

q = deque()
q.append(root)
parent[root] = root
depth[root] = root

while len(q): # bfs 식
    x = q.popleft()
    for n in g[x]:
        if parent[n] == 0: # 아직 부모 노드 모름
            q.append(n)
            parent[n] = x
            depth[n] = depth[x] + 1
M = int(input())
while M > 0:
    x,y = list(map(int,input().split()))
    if depth[x] > depth[y]: # 깊이가 더 깊은 노드를 y로 둠
        t = copy(x)
        x = y
        y = t
    while depth[x] != depth[y]:
        y = parent[y]

    if x==y:
        print(x)
    else:
        while parent[x] != parent[y]:
            x = parent[x]
            y = parent[y]
        print(parent[x])
    M-=1
sys.exit()
