# <드래곤커브>
# https://www.acmicpc.net/problem/15685

import sys
from collections import deque
from copy import deepcopy

input = lambda : sys.stdin.readline()
di = [1,0,-1,0], [0,-1,0,1] # (x,y)
min_x, min_y = 101,101
max_x, max_y = -1,-1

def rotate(ox, oy, x,y):
    rx,ry = x-ox, y-oy
    return (-ry+ox, rx+oy)

def update_xy(x,y):
    global min_x, min_y, max_x, max_y
    min_x = min(min_x, x)
    min_y = min(min_y, y)
    max_x = max(max_x, x)
    max_y = max(max_y, y)

n = int(input())
ptSet = set()
while n>0:
    x,y,d,g = list(map(int, input().split()))
    ptSet.add((x,y))
    update_xy(x,y)
    end_x, end_y = x+di[0][d], y+di[1][d]
    ptSet.add((end_x, end_y))
    update_xy(end_x,end_y)
    q = deque()
    q.append((x,y))
    for i in range(g):
        tmp_q = deque()
        while q:
            r_x, r_y = q.popleft()
            new_x, new_y = rotate(end_x, end_y, r_x, r_y)
            tmp_q.append((r_x,r_y))
            ptSet.add((new_x, new_y))
            update_xy(new_x, new_y)
            if len(q) == 0:
                tmp_q.appendleft((end_x,end_y))
                end_x = new_x
                end_y = new_y
            else:
                tmp_q.appendleft((new_x,new_y))
        q = deepcopy(tmp_q)
    n-=1
count = 0
ddi = [1,1,0], [0,1,1]
for iy in range(min_y, max_y):
    for ix in range(min_x, max_x):
        if (ix,iy) not in ptSet:
            continue
        found = True
        for ii in range(3):
            nix, niy = ix+ddi[0][ii], iy+ddi[1][ii]
            if (nix,niy) not in ptSet:
                found = False
                break
        if found:
            count += 1
print(count)
