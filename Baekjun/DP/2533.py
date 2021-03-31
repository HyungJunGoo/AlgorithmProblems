# 2533 <사회망 서비스>

import sys
sys.setrecursionlimit(1000000)

input = lambda: sys.stdin.readline()
visited = set()

def solution(n):
    visited.add(n)
    check_leaf = True
    for next in t[n-1]:
        if next not in visited:
            check_leaf = False
            solution(next)
            d[n-1][0] += min(d[next-1][0], d[next-1][1])
            d[n-1][1] += d[next-1][0]
    d[n-1][0] += 1
    if check_leaf == True:
        d[n-1][0] = 1 # n번 노드가 얼리 어댑터인 경우
        d[n-1][1] = 0 # n번 노드가 얼리 어댑터가 아닌 경우

    return


if __name__ == "__main__":
    N = int(input())
    t = list()
    for _ in range(N):
        t.append([])

    for _ in range(N-1):
        a, b = list(map(int, input().split()))
        t[a-1].append(b)
        t[b-1].append(a)
    d = list()
    for _ in range(N):
        d.append([0,0])

    solution(1)
    print(min(d[0]))