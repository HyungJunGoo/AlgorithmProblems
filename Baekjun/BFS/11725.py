#11725 <트리의 부모 찾기>

from collections import deque
import sys

input = lambda: sys.stdin.readline()

def bfs(q):
    global g
    global result
    while q:
        node = q.popleft()
        if len(g[node])==0:
            continue
        for v in g[node]:
            if v != result[node-1]:
                q.append(v)
                result[v-1]=node
    return

if __name__ == "__main__":
    
    N=int(input())
    g = {i : [] for i in range(1,N+1)}
    for _ in range(N-1):
        a,b = list(map(int, input().split()))
        g[a].append(b)
        g[b].append(a)
    q=deque()
    result=[0]*N
    for n in g[1]:
        q.append(n)
        result[n-1]=1
    bfs(q)
    result.pop(0)
    for i in result:
        print(i)
