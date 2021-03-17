# 2636 <치즈>

import sys
from copy import deepcopy
input = lambda: sys.stdin.readline()

di = (-1,1,0,0), (0,0,-1,1)

#세로, 가로
N,M=list(map(int, input().split()))

board = [list(map(int, input().split())) for _ in range(N)]

def airMark(i,j):
    board[i][j]=2
    for idx in range(4):
        ni,nj=i+di[0][idx], j+di[1][idx]
        if 0<=ni<N and 0<=nj<M:
            if board[ni][nj] == 0:
                airMark(ni,nj)


def solution():
    for i in range(N):
        for j in range(M):
            airCondition=False
            if board[i][j] == 1:
                for idx in range(4):
                    ni,nj=i+di[0][idx], j+di[1][idx]
                    if 0<=ni<N and 0<=nj<M:
                        if board[ni][nj]==2:
                            airCondition=True
                            break
                if airCondition == True:
                    board[i][j]=3 # melting
    return

#시간
t=0
while 1:
    airMark(0,0)
    t+=1
    solution()
    c_count=0
    left_count=0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 3:
                c_count+=1
            elif board[i][j] == 1:
                left_count+=1
    if left_count == 0:
        print(t)
        print(c_count)
        break
    for i in range(N):
        for j in range(M):
            if board[i][j] != 1:
                board[i][j] = 0

