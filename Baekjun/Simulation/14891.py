# 14891 <톱니바퀴>

import sys
import copy

input = lambda: sys.stdin.readline()

gears = [[0]*8 for _ in range(4)]

for i in range(4):
    gear = input()
    gear = gear[:-1]
    for j in range(len(gear)):
        gears[i][j] += int(gear[j])    

def rotate(status):

    for i in range(4):
        if status[i] == 1:
            last = copy.copy(gears[i][7])
            for j in range(7,-1,-1):
                if j==0:
                    gears[i][j] = last
                else:
                    gears[i][j] = gears[i][j-1]
        elif status[i] == -1:
            first = copy.copy(gears[i][0])
            for j in range(8):
                if j==7:
                    gears[i][j] = first
                else:
                    gears[i][j] = gears[i][j+1]

def statuscheck(a,b):
    status = [0]*4
    status[a]=b
    for i in range(a+1, 4):
        if gears[i][6] != gears[i-1][2]:
            status[i] = -status[i-1]
    for i in range(a-1, -1, -1):
        if gears[i][2] != gears[i+1][6]:
            status[i] = -status[i+1]
    rotate(status)
    return


k = int(input())
for _ in range(k):
    a,b=list(map(int, input().split()))
    a=a-1
    statuscheck(a,b)
answer = 0
for i in range(4):
    if gears[i][0] == 1:
        answer+= pow(2,i)
print(answer)
