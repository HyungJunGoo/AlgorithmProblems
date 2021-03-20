# 2174 <로봇 시뮬레이션>

import sys

input = lambda: sys.stdin.readline()

#NESW
di=[-1,0,1,0],[0,1,0,-1]

# a: 가로길이  b: 세로길이
a,b=list(map(int,input().split()))
l=[[0]*a for _ in range(b)]
# n: 로봇 수 m: 명령 수
n,m=list(map(int,input().split()))

robot={i: None for i in range(1,n+1)}

for i in range(1,n+1):
    x,y,d=list(input().split())
    x,y=int(x),int(y)
    if d == 'N':
        d=0
    elif d=='E':
        d=1
    elif d=='S':
        d=2
    elif d=='W':
        d=3
    x=x-1
    y=b-y
    l[y][x]=i
    robot[i]=[d, [y,x]]#key : robot number , value : [direction, location]
for _ in range(m):
    rn, cmd, it=list(input().split())
    rn,it=int(rn),int(it)
    for _ in range(it):
        if cmd == 'F':
            y,x = robot[rn][1]
            ny,nx = y+di[0][robot[rn][0]], x+di[1][robot[rn][0]]
            if 0<=ny<b and 0<=nx<a:
                if l[ny][nx] != 0:
                    print(f"Robot {rn} crashes into robot {l[ny][nx]}")
                    sys.exit()
                l[y][x]=0
                l[ny][nx]=rn
                robot[rn][1] = [ny,nx]
            else:
                print(f"Robot {rn} crashes into the wall")
                sys.exit()
        elif cmd == 'L':
            if robot[rn][0] > 0:
                robot[rn][0] -= 1
            elif robot[rn][0] == 0:
                robot[rn][0] = 3
        elif cmd == 'R':
            if robot[rn][0] < 3:
                robot[rn][0] += 1
            elif robot[rn][0] == 3:
                robot[rn][0] = 0
print("OK")