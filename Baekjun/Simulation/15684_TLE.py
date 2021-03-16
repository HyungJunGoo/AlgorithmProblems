# 15684 <사다리 조작>
# Time Limit Exceeded
from itertools import combinations
from copy import deepcopy as dc
import sys

input = lambda: sys.stdin.readline()


N,M,H=list(map(int,input().split()))

d={i: [] for i in range(1,N+1)}
# key : 세로선 번호
# value list : 세로선 번호 기준, (오른쪽으로 이어지는 간선의 높이, 연결된 세로선 번호)
candidates=[]
for r in range(1,H+1):
    for c in range(1,N):
        candidates.append((r,c))
# candidates = [(오른쪽으로 이어지는 간선높이, 세로선 번호)]
for _ in range(M):
    a,b=list(map(int,input().split()))
    d[b].append((a, b+1))
    d[b+1].append((a, b))
    candidates.remove((a,b))
    try:
        candidates.remove((a,b-1))
    except ValueError:
        pass
    try:
        candidates.remove((a,b+1))
    except ValueError:
        pass

def solution():
    global d
    if len(candidates)==0:
        print(-1)  
        return
    condition=True
    for idx in range(1, N+1):
        cur_n=idx
        for h in range(1,H+1):
            if (h, cur_n+1) in d[cur_n]:
                cur_n=cur_n+1
                continue
            if (h,cur_n-1) in d[cur_n]:
                cur_n=cur_n-1
                continue
        if cur_n!=idx:
            condition=False
            break
    if condition==True:
        print(0)
        return
    for i in range(1,4):
        caseList = list(combinations(candidates,i))

        for case in caseList:
            temp_d = dc(d)
            for c in case:
                (a,b) = c
                if (b > 1 and (a,b-1) in d[b-1]) or (b < N and(a, b+1) in d[b+1]):
                    continue
                d[b].append((a,b+1))
                d[b+1].append((a,b))
            condition=True
            for idx in range(1, N+1):
                cur_n=idx
                for h in range(1,H+1):
                    # print(cur_n, h, end=" ")
                    if (h, cur_n+1) in d[cur_n]:
                        cur_n=cur_n+1
                        continue
                    if (h,cur_n-1) in d[cur_n]:
                        cur_n=cur_n-1
                        continue
                if cur_n!=idx:
                    condition=False
                    break
            d=temp_d
            if condition==True:
                print(case)
                print(i)
                return
    print(-1)
    return

solution()