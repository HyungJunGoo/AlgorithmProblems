# 15685 <사다리 조작>

import sys
input = lambda: sys.stdin.readline()

def validate():
    for i in range(1,N+1):
        cur_n = i
        for j in range(1, H+1):
            if l[cur_n][j] == 1:
                cur_n +=1
            elif l[cur_n-1][j] == 1:
                cur_n -=1
        if cur_n != i:
            # print(f"cur_n : {cur_n}")
            return False
    return True

def dfs(cnt, h, num):
    global answer
    
    if cnt == num:
        if validate() == True:
            answer=cnt
        return 
    
    for i in range(h, H+1):
        for j in range(1,N):
            if l[j][i] == 1:
                continue
            if j-1>0 and l[j-1][i] == 1:
                continue
            if j+1 < N and l[j+1][i] == 1:
                continue
            l[j][i]=1
            dfs(cnt+1,i,num)
            l[j][i]=0

if __name__ == "__main__":
    N,M,H=list(map(int, input().split()))

    l = [list(0 for _ in range(H+1)) for _ in range(N+1)]
    for _ in range(M):
        a,b=list(map(int, input().split()))
        l[b][a]=1
    answer=-1
    condition = False
    for n in range(4):
        dfs(0,1,n)
        if answer > -1:
            print(answer)
            condition=True
            break
    if condition == False:
        print(-1)

