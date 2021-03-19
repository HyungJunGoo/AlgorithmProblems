#16236 <아기상어>

from collections import deque
import sys

input = lambda: sys.stdin.readline()

dx=[-1,0,0,1]
dy=[0,-1,1,0]

def bfs(x,y,w,t,eat):
    # parameter
    # x,y : 아기상어의 위치
    # w: 아기상어의 몸무게, eat: 아기상어가 먹은 개수
    # t: 시간 (return)
    # q : 탐색할 위치, can_eat: 먹을 수 있는 상어 위치
    q, can_eat=deque(), []
    q.append([x,y])
    c=[[-1]*n for _ in range(n)]
    c[x][y]=t

    while q:
        ql=len(q)
        while ql:
            x,y=q.popleft() #local in while loop x,y
            for i in range(4):
                nx,ny=x+dx[i], y+dy[i]
                if 0<=nx<n and 0<=ny<n:
                    if c[nx][ny]==-1:
                        if b[nx][ny] == 0 or b[nx][ny] == w:
                            c[nx][ny]=c[x][y]+1
                            q.append([nx,ny])
                        elif 0<b[nx][ny]<w:
                            can_eat.append([nx,ny])
            ql-=1
        if can_eat:
            nx,ny=min(can_eat)
            eat+=1
            if eat == w:
                eat=0
                w+=1
            b[nx][ny]=0
            return nx,ny,w,c[x][y]+1,eat
    print(t)
    sys.exit()
    return

n=int(input())
b=[list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if b[i][j] == 9:
            x,y=i,j
            b[i][j]=0

#init
w = 2
t = 0
eat = 0

while 1:
    x,y,w,t,eat=bfs(x,y,w,t,eat)

