# 7576번 <토마토>

import sys
from collections import deque

input = lambda: sys.stdin.readline()

direction = [(0, -1),(0, 1), (-1, 0), (1, 0)]

def solution(t1, M, N, totalCount, empty):
    q = deque()
    checkCount = 0
    for t in t1:
        q.append(t)
        checkCount += 1
    day = 0
    while len(q)>0:
        dayQ = deque()
        while len(q)>0:
            poppedTomato = q.pop()
            t1.add(poppedTomato)
            dayQ.append(poppedTomato)
        while len(dayQ)>0:
            tomato = dayQ.popleft()
            for d in range(4): # 4방향 체크
                if (1 <= tomato[0] + direction[d][0] <= N) and (1<= tomato[1] + direction[d][1] <= M):
                    if (tomato[0] + direction[d][0], tomato[1] + direction[d][1]) not in t1 and (tomato[0] + direction[d][0], tomato[1] + direction[d][1]) not in empty:
                        q.append((tomato[0] + direction[d][0], tomato[1] + direction[d][1]))
                        t1.add((tomato[0] + direction[d][0], tomato[1] + direction[d][1]))
                        checkCount += 1
        if len(q) == 0: break
        day += 1
    
    if checkCount != totalCount:
        print(-1)
    else:
        print(day)
                    
    return

if __name__ == "__main__":
    M, N = list(map(int, input().split())) # M 가로 길이 , N 세로 길이
    t1 = set() #익은 토마토를 담을 리스트
    totalCount = 0 # 최종으로 익어야할 토마토 갯수
    empty = set() # 상자 내의 비어있는 칸 위치
    for r in range(1, N+1):
        l = list(map(int, input().split()))
        for c in range(1, M+1):
            if l[c-1] == 1:
                t1.add((r,c))
                totalCount+=1
            elif l[c-1] == -1:
                empty.add((r,c))
            else:
                totalCount+=1
    solution(t1, M, N, totalCount, empty)
