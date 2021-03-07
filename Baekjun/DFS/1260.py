# 1260 <DFS/BFS>

import sys
from collections import deque

input = lambda: sys.stdin.readline()

def solution(N, M, V, g):
    
    dfs_visited = []
    DFS(g, V, dfs_visited)
    print(*dfs_visited)

    bfs_visisted = []
    BFS(g, V, bfs_visisted)
    print(*bfs_visisted)
    return

def DFS(g, V, visited):
    visited.append(V)
    for n in g[V]:
        if n in visited: continue
        DFS(g, n, visited)

def BFS(g, V, visited):
    q = deque()
    visited.append(V)
    for n in g[V]:
        if n not in visited:
            q.append(n)

    while len(q)>0:
        v = q.popleft()
        visited.append(v)
        for v_n in g[v]:
            if v_n not in visited and v_n not in q:
                q.append(v_n)
    return
if __name__ == "__main__":
    N, M, V = list(map(int, input().split()))

    g = {i: [] for i in range(1, N+1)}
    for _ in range(M):
        a, b = list(map(int, input().split()))
        g[a].append(b)
        g[b].append(a)
    for i in range(1,N+1):
        if len(g[i]) != 0:
            g[i] = sorted(g[i])
    solution(N, M, V, g)