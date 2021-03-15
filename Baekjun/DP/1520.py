#1520 <내리막길>

import sys
sys.setrecursionlimit(10000000)
input = lambda: sys.stdin.readline()

di=(-1,1,0,0),(0,0,-1,1)
def dfs(i,j):
    
    if i==m-1 and j==n-1:
        return 1
    if d[i][j] != -1:
        return d[i][j]
    d[i][j]=0
    for idx in range(4):
        n_i=i+di[0][idx]
        n_j=j+di[1][idx]
        if 0<=n_i<m and 0<=n_j<n:
            if h[n_i][n_j]<h[i][j]:
                d[i][j]+=dfs(n_i, n_j)
    return d[i][j]

if __name__ == "__main__":
    m, n=list(map(int, input().split()))
    h = [list(map(int, input().split())) for _ in range(m)]
    d = [[-1]*n for _ in range(m)]

    print(dfs(0,0))
    