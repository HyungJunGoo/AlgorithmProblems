# 1012
import sys
from collections import deque
sys.setrecursionlimit(100000)

def main():
    T = int(sys.stdin.readline())
    for _ in range(T):
        #가로 M, 세로 N, 배추 수 K
        M, N, K = map(int, sys.stdin.readline().split())
        yard = [[0 for _ in range(M)]for _ in range(N)]
        cabbage = deque()

        for _ in range(K):
            x,y = map(int, sys.stdin.readline().split())
            yard[y][x] = 1
            cabbage.append([y,x])
        ans = 0
        y, x = cabbage[0]
        while True:
            
            ans += dfs(yard, cabbage, x, y)
            if len(cabbage) == 0: break
            y, x = cabbage[0]
        print(ans)
    return

def dfs(yard, cabbage, x, y):

    if yard[y][x] == 0: return 0
    else:
        yard[y][x] -=1
        cabbage.remove([y,x])
        cnt = 0 
        if y > 0: # up
            cnt += dfs(yard, cabbage, x, y-1)
        if y < len(yard)-1: #down
            cnt += dfs(yard, cabbage, x, y+1)
        if x > 0: #left
            cnt += dfs(yard, cabbage, x-1, y)
        if x < len(yard[0])-1: # right
            cnt += dfs(yard, cabbage, x+1, y)
        
        return 1
if __name__ == "__main__":
    main()
