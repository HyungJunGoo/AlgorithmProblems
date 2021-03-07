# 1074 Z

import sys
sys.setrecursionlimit(100000)
input = lambda: sys.stdin.readline()
cnt = 0
def solution(N, r, c):
    dfs(N, 0, 0, r, c)
    return

def dfs(N, i, j, r, c):
    global cnt
    if N == 1:
        if i == r and j == c:
            print(cnt)
            return
        cnt += 1
        if i == r and j+1 ==c:
            print(cnt)
            return
        cnt += 1
        if i+1 == r and j ==c:
            print(cnt)
            return
        cnt += 1
        if i+1 == r and j+1 ==c:
            print(cnt)
            return
    if i<= r < i+2**(N-1) and j<= c < j+2**(N-1):
        # 1section
        print("s1")
        dfs(N-1, i, j, r, c)
    elif i<= r < i+2**(N-1) and c >= j+2**(N-1):
        # 2section
        print("s2")
        cnt += (2**(N-1))**2
        dfs(N-1, i, j+2**(N-1), r, c)
    elif r >= i+2**(N-1) and j<=c < j+2**(N-1):
        # 3section
        print("s4")
        cnt += (2**(N-1))**2 * 2
        dfs(N-1, i+2**(N-1), j, r, c )
    elif r >= i+2**(N-1) and c >= j+2**(N-1):
        # 4section
        print("s4")
        cnt += (2**(N-1))**2 * 3
        dfs(N-1, i+2**(N-1), j+2**(N-1), r, c)

    
if __name__ == "__main__":
    N, r, c = list(map(int, input().split()))
    solution(N, r, c)