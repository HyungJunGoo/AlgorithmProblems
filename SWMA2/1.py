import sys

input = lambda: sys.stdin.readline()

di = (-1,1,0,0),(0,0,-1,1)

def solution():
    global k_find, p_find
    soma = None
    K=None
    P=None
    for i in range(N):
        for j in range(M):
            if m[i][j] == 3:
                soma=(i,j)
            elif m[i][j] == 4:
                K=(i,j)
            elif m[i][j] == 2:
                P=(i,j)
    visited=[]
    search(soma[0], soma[1], 4, visited)
    if k_find == False:
        print(0)
        return 
    visited=[]
    search(K[0],K[1], 2, visited)
    if p_find == False:
        print(0)
        return
    print(1)
    return

def search(i,j, goal, visited):
    global k_find, p_find
    if m[i][j] == goal:
        if goal==4:
            k_find=True
        if goal == 2:
            p_find=True
        return
    if (i,j) in visited:
        return
    visited.append((i,j))
    
    for idx in range(4):
        n_i=i+di[0][idx]
        n_j=j+di[1][idx]
        if 0<=n_i<N and 0<=n_j<M:
            if m[n_i][n_j] != 1:
                search(n_i,n_j,goal,visited)
    return

if __name__=="__main__":
    T=int(input())
    for _ in range(T):
        N, M = list(map(int, input().split()))
        m = [list(map(int, input().split())) for _ in range(N)]
        k_find=False
        p_find=False
        solution()