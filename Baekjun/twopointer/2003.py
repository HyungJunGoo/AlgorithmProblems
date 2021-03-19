# 2003 <수들의 합2>

import sys

input = lambda: sys.stdin.readline()

N,M=list(map(int, input().split()))

a=list(map(int, input().split()))

p1,p2=0,0
s = a[0]
cnt=0 #return
while 1:
    if s == M:
        cnt+=1
        if p1==p2:
            if p2 <N-1:
                p2+=1
                s+=a[p2]
            else:
                print(cnt)
                break
            continue
        elif p1<p2:
            s-=a[p1]
            p1+=1
            continue
    elif s < M:
        if p2 < N-1:
            p2+=1
            s+=a[p2]
            continue
        else:
            print(cnt)
            break
    elif s > M:
        if p1==p2:
            if p2 <N-1:
                p2+=1
                s+=a[p2]
                continue
            else:
                print(cnt)
                break
        elif p1<p2:
            s-=a[p1]
            p1+=1
            continue
