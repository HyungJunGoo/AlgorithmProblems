# 16234 <인구이동> 

import sys
sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline()
d = (-1,0,1,0), (0,1,0,-1)

def solution():
    answer = 0
    while 1:
        condition = True
        visited = {(i, j): False for i in range(N) for j in range(N)}
        for i in range(N):
            for j in range(N):
                if visited[(i,j)] == False:
                    visited[(i,j)] = True
                    linkedNode = [(i,j)]
                    dfs(i,j,visited,linkedNode)
                    if len(linkedNode) > 1: 
                        condition = False
                    s = 0
                    for y,x in linkedNode:
                        s += b[y][x]
                    v = s//len(linkedNode)
                    for (y,x) in linkedNode:
                        b[y][x] = v
                    
        if condition: break
        answer += 1
    print(answer)
    return  

def dfs(i,j,visited,linkedNode):
    for k in range(4):
        y = i+d[1][k]
        x = j+d[0][k]
        if 0<=y<N and 0<=x<N and visited[(y,x)] == False:
            if L<=abs(b[y][x] - b[i][j])<=R:
                visited[(y,x)] = True
                linkedNode.append((y,x))
                dfs(y,x, visited, linkedNode)

if __name__ == "__main__":
    N, L, R = list(map(int, input().split()))
    b = []
    for _ in range(N):
        b.append(list(map(int, input().split())))

    solution()