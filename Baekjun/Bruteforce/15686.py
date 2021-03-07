#15686 치킨 배달

import sys
from itertools import combinations

input = lambda: sys.stdin.readline()

def solution(houses, chickenStore, M):
    chickenCombi = list(combinations(chickenStore, M))
    D = sys.maxsize
    for combi in chickenCombi:
        D = min(D,getDist(houses, combi))
    print(D)
    return

def getDist(houses, combi):
    sumD = 0
    for house in houses:
        d = sys.maxsize
        for chicken in combi:
            d = min(d, abs(house[0]-chicken[0]) + abs(house[1]-chicken[1]))
        sumD += d
    return sumD

if __name__ == "__main__":
    N, M = list(map(int, input().split()))

    houses = []
    chickenStore = []

    for r in range(1, N+1):
        l = list(map(int, input().split()))
        for c in range(1,N+1):
            if l[c-1] == 1:
                houses.append((r, c))
            elif l[c-1] == 2:
                chickenStore.append((r,c))
    
    solution(houses, chickenStore, M)