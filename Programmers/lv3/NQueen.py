# N - Queen
# https://programmers.co.kr/learn/courses/30/lessons/12952
from copy import copy
answer = 0
arr = None

def dfs(h, i, visited):
    global answer
    # diagonal check
    c_idx = copy(i)-1
    for r in range(h-1,0,-1):
        if c_idx - (h-r) >=0 and c_idx - (h-r)<len(visited)-1:
            if arr[r-1][c_idx-(h-r)] == 1:
                return
        if c_idx + (h-r) >= 0 and c_idx + (h-r)<len(visited)-1:
            if arr[r-1][c_idx+(h-r)] == 1:
                return
    arr[h-1][i-1]=1
    visited[i] = True # Column Update
    if h == len(visited)-1:#End point
        answer += 1
        arr[h-1][i-1] = 0
        visited[i] = False
        return

    for j in range(1, len(visited)):
        if visited[j] == False:
            dfs(h+1, j, visited)
    arr[h-1][i-1] = 0
    visited[i] = False
    return

def solution(n): # n = 4
    global answer, arr
    answer = 0
    visited = [False for _ in range(n+1)]
    arr = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(1, n+1):
        dfs(1, i, visited)
    return answer

solution(1)
print(answer)