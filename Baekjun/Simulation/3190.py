# 3190 <뱀>

import sys
from copy import deepcopy
from collections import deque
input = lambda: sys.stdin.readline()

N = int(input())
di=(-1,1,0,0),(0,0,-1,1)
board = [[0]*N for _ in range(N)]

K=int(input())

for _ in range(K):
    r,c=list(map(int, input().split()))
    board[r-1][c-1] = 1
L=int(input())
changeT = dict()
for _ in range(L):
    t, d = list(input().split())
    t = int(t)
    changeT[t]=d


time=0
current = 3 #오른쪽
x,y=0,0
snakes = deque()
snakes.append((x,y))
while 1:
    # 방향 변경 확인
    if time in changeT.keys():
        # print(f"change direction at time {time} from {current}")
        if current == 0:
            if changeT[time] == 'L':
                current = 2
            elif changeT[time] == 'D':
                current = 3
        elif current == 1:
            if changeT[time] == 'L':
                current = 3
            elif changeT[time] == 'D':
                current = 2
        elif current == 2:
            if changeT[time] == 'L':
                current = 1
            elif changeT[time] == 'D':
                current = 0
        elif current == 3:
            if changeT[time] == 'L':
                current = 0
            elif changeT[time] == 'D':
                current = 1
    
    nx,ny=snakes[0][0]+di[0][current], snakes[0][1]+di[1][current]
    
    if 0<=nx<N and 0<=ny<N:
        if (nx,ny) in snakes: #자기 몸 발견
            time+=1
            break
        if board[nx][ny] == 1: #사과 발견
            board[nx][ny] = 0
            snakes.insert(0,(nx,ny))
        else: #이동
            snakes.insert(0,(nx,ny))
            snakes.pop()
    else:
        time+=1
        break
    time+=1
print(time)