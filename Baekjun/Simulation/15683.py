#15683 <감시>

import sys
import copy

input = lambda: sys.stdin.readline()

# 상, 하, 좌, 우
di = (-1, 1, 0, 0), (0, 0, -1, 1)

def check(n):#n번째 cctv
    if n == n_cc:
        countempty()
        return
    i,j = cc[n][0], cc[n][1]
    if b[i][j] == 1:
        mark(n,[[0],[1],[2],[3]])
    elif b[i][j] == 2:
        mark(n,[[2,3], [0,1]])
    elif b[i][j] == 3:
        mark(n, [[0,3], [0,2], [1,2], [1,3]])
    elif b[i][j] == 4:
        mark(n,[[0,2,3],[0,1,2],[1,2,3],[0,1,3]])
    elif b[i][j] == 5:
        mark(n,[[0,1,2,3]])
    return

def mark(n,l):
    i,j = cc[n][0], cc[n][1]
    for idx in range(len(l)): # 체크해야하는 방향 수 
        ll = l[idx]
        for nn in range(len(ll)): # n 번 CCTV마다 볼 수 있는 방향
            dd = ll[nn]
            x,y=copy.copy(i), copy.copy(j)
            while 1:
                nx,ny=x+di[0][dd], y+di[1][dd]
                if nx>=0 and nx < N and ny>=0 and ny < M:
                    if b[nx][ny] == 6:
                        break
                    if b[nx][ny] == 0 or b[nx][ny]>=9:
                        b[nx][ny] += 9
                else:
                    break
                (x,y) = (nx, ny)
        check(n+1)
        for nn in range(len(ll)): # n 번 CCTV마다 볼 수 있는 방향 (지우기)
            dd = ll[nn]
            x,y=copy.copy(i), copy.copy(j)
            while 1:
                nx,ny=x+di[0][dd], y+di[1][dd]
                if nx>=0 and nx < N and ny>=0 and ny < M:
                    if b[nx][ny] == 6:
                        break
                    if b[nx][ny] >= 9:
                        b[nx][ny] -= 9
                else:
                    break
                (x,y) = (nx, ny)

def countempty():
    global result
    cnt=0
    for i in range(N):
        for j in range(M):
            if b[i][j] == 0:
                cnt+=1
    result = min(result, cnt)
    return

result=100
N,M = list(map(int, input().split()))

b=[list(map(int, input().split())) for _ in range(N)]

cc = []
for i in range(N):
    for j in range(M):
        if b[i][j] >0 and b[i][j] < 6:
            cc.append((i,j))

n_cc = len(cc)
check(0)
print(result)