# 14499 <주사위 굴리기>

import sys

input = lambda: sys.stdin.readline()

N, M, x, y, K = list(map(int, input().split()))

b = [list(map(int, input().split())) for _ in range(N)]

d = {i : 0 for i in range(1,7)}

cmds = list(map(int, input().split()))

di = (0,0,-1,1), (1,-1,0,0) # 방향
#init
top = 1
bottom=6
north=4
south=3
west=5
east=2

for cmd in cmds:
    nx, ny = x+di[0][cmd-1], y+di[1][cmd-1]
    if 0<=nx<N and 0<=ny<M:
        if cmd == 1: #동쪽 이동
            tmp_top=top
            top=west
            east=tmp_top
            west=bottom
            bottom=7-top
        elif cmd ==2:#서쪽 이동
            tmp_top=top
            top=east
            west=tmp_top
            east=bottom
            bottom=7-top
        elif cmd ==3:#북쪽 이동
            tmp_top=top
            top=south
            north=tmp_top
            south=bottom
            bottom=7-top
        elif cmd ==4:#남쪽 이동
            tmp_top=top
            top=north
            south=tmp_top
            north=bottom
            bottom=7-top
        print(d[top])
        if b[nx][ny] == 0:
            b[nx][ny] = d[7-top]
        else:
            d[7-top] = b[nx][ny]
            b[nx][ny]=0
        (x,y)=(nx,ny)
