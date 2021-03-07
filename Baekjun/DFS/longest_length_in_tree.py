# 1167
import sys
from collections import deque

t = dict()

def dfs(node, V):
    visited = [False] * (V+1)
    visited[node] = True
    stack = deque()
    dist = 0
    farest_n = 0

    for v, e in t[node].items():
        stack.append([v,e])
    while len(stack) > 0:
        s = stack.popleft()
        v=s[0]
        e=s[1]
        visited[v] = True
        farest_n, dist = (v, e) if e > dist else (farest_n, dist)
        for n_v, n_e in t[v].items():
            if visited[n_v] == False:
                stack.append([n_v, n_e+e])
    return dist, farest_n
    
        
def main():
    V = int(sys.stdin.readline())
    for _ in range(V):
        a = list(map(int ,sys.stdin.readline().split()))
        i = a[0]
        a = a[1:-1]
        d = dict()
        for idx in range(0, len(a), 2):
            d[a[idx]] = a[idx+1]
        t[i] = d
    _, far_n = dfs(1,V)
    answer_dist,_ = dfs(far_n, V)
    print(answer_dist)
    return

if __name__ == "__main__":
    main()