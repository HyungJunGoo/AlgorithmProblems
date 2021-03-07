import sys
sys.setrecursionlimit(100000)
count = 0
def solution(n):
    n1 = n
    n0 = n
    dfs(n1, n0)
    return count

def dfs(n1, n0):
    if n1 > n0: return
    global count
    if n1 == 0 and n0 == 0: 
        count+=1 
        return
    if n1 > 0: dfs(n1-1, n0)
    if n0 > 0:
        dfs(n1, n0-1)
    return

print(solution(3))