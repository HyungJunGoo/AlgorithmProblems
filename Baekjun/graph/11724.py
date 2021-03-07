# 11724 연결 요소의 갯수

import sys
sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline()

def solution(g,N):
    count = 0
    visited = []
    for n in range(1, N+1):
        if n not in visited:
            dfs(g, n, visited)
            count += 1
    print(count)
    return

def dfs(g, v, visited):
    visited.append(v)
    for n in g[v]:
        if n not in visited:
            dfs(g, n, visited)

if __name__ == "__main__":

    N, M = list(map(int, input().split()))
    g = {i : [] for i in range(1, N+1)}
    for _ in range(M):
        a,b = list(map(int, input().split()))
        g[a].append(b)
        g[b].append(a)
    solution(g,N)
    pass