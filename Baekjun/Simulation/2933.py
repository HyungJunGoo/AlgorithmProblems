# 2933 <미네랄>

from collections import deque
import sys
input = lambda: sys.stdin.readline()


di=(-1,1,0,0),(0,0,-1,1)

def attack(l, h):
    i= R-h
    x=-1
    if l==1:
        for c in range(C):
            if mineral[i][c] == 'x':
                mineral[i][c] = '.'
                x=c
                break
    else:
        for c in range(C-1, -1, -1):
            if mineral[i][c] == 'x':
                mineral[i][c]='.'
                x=c
                break
    # add to check list
    for i in range(4):
        nh=h+di[0][i]
        nx=x+di[1][i]
        if 0<=nh<R and 0<=nx<C:
            if mineral[nh][nx]=='x':
                dq.append([nh,nx])
    return

def bfs(r,c):
    q=deque()
    check=[[0]*C for _ in range(R)]
    fall_list = []
    q.append([r,c])
    check[r][c]=1
    while q:
        y,x= q.popleft()
        if y==R-1:
            return
        if mineral[y+1][x]=='.':
            fall_list.append([y,x])
        for i in range(4):
            ny=y+di[0][i]
            nx=x+di[1][i]
            if 0<=ny<R and 0<=nx<C:
                if mineral[ny][nx] == 'x' and not check[ny][nx]:
                    check[ny][nx]=1
                    q.append([ny,nx])
    fall(check, fall_list)

def fall(check, fall_list):
    k, flag= 1, 0
    while 1:
        for i,j in fall_list:
            if i+k == R-1:
                flag=1
                break
            if mineral[i+k+1][j] == 'x' and not check[i+k+1][j]:
                flag=1
                break
        if flag:
            break
        k+=1
    for i in range(R-2, -1, -1):
        for j in range(C):
            if mineral[i][j]=='x' and check[i][j]:
                mineral[i][j]='.'
                mineral[i+k][j]='x'

R,C=list(map(int, input().split()))
mineral = [list(input())[:-1] for _ in range(R)]
n=int(input())
heights=list(map(int,input().split()))
dq=deque()

left = 1
while n:
    index = heights.pop(0)
    attack(left, index)

    while dq:
        x, y = dq.popleft()
        bfs(x, y)

    left *= -1
    n -= 1

for i in range(R):
    for j in range(C):
        print(mineral[i][j], end='')
    print()