import sys

sys.setrecursionlimit(10*8)
input = lambda: sys.stdin.readline()

def solution():
    global d,N
    result=0
    for n in range(1,N+1):
        visited=set()
        find=False
        find = cyclecheck(n, d[n], d, visited)
        cnt=len(visited)+1
        if find==True:
            if cnt > result:
                result = cnt
    print(result)
    return

def cyclecheck(start, n, d, visited):
    if n == start:
        return True
    if d[n] in visited:
        return False
    visited.add(n)
    return cyclecheck(start, d[n], d, visited)

if __name__ == "__main__":
    # 발판 개수
    N = int(input())
    d={i:0 for i in range(1,N)}
    l = list(map(int, input().split()))
    
    for i,n in enumerate(l):
        d[i+1]= (i+1)+n
    print(d)
    solution()