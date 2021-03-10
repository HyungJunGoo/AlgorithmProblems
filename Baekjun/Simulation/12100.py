# 12100 <2048(EASY)>
# 

import sys
import copy as cp
sys.setrecursionlimit(100000)
input = lambda: sys.stdin.readline()


def moveBlocks(di):
    
    if di==0:
        # r = 0 ~ N-1
        for c in range(N):
            idx = 0 
            for r in range(1, N):
                if board[r][c]:
                    temp = board[r][c]
                    board[r][c] = 0
                    if board[idx][c] == 0:
                        board[idx][c] = temp
                    elif board[idx][c] == temp:
                        board[idx][c] = temp*2
                        idx += 1
                    else:
                        idx += 1
                        board[idx][c] = temp
    elif di==1:
        # c = N-1 ~ 0
        for r in range(N):
            idx = N-1
            for c in range(N-2, -1,-1):
                if board[r][c]:
                    temp=board[r][c]
                    board[r][c] = 0
                    if board[r][idx] == 0:
                        board[r][idx] = temp
                    elif board[r][idx] == temp:
                        board[r][idx] = temp*2
                        idx -=1
                    else:
                        idx-=1
                        board[r][idx] = temp
    elif di==2:
        # r = N-1 ~ 0
        for c in range(N):
            idx = N-1
            for r in range(N-2, -1, -1):
                if board[r][c]:
                    temp = board[r][c]
                    board[r][c] = 0
                    if board[idx][c] == 0:
                        board[idx][c] = temp
                    elif board[idx][c] == temp:
                        board[idx][c] = temp*2
                        idx -= 1
                    else:
                        idx -= 1
                        board[idx][c] = temp
    else:
        # c = 0 ~ N-1
        for r in range(N):
            idx = 0
            for c in range(1, N):
                if board[r][c]:
                    temp=board[r][c]
                    board[r][c] = 0
                    if board[r][idx]==0:
                        board[r][idx] = temp
                    elif board[r][idx] ==temp:
                        board[r][idx] = 2*temp
                        idx += 1
                    else:
                        idx+=1
                        board[r][idx]=temp


def dfs(n):
    global board
    global maxBlock
    if n == 5:
        for r in range(N):
            for c in range(N):
                maxBlock = max(maxBlock, board[r][c])
        return
    cp_Board = cp.deepcopy(board)
    for i in range(4):
        moveBlocks(i)
        dfs(n+1)
        board=cp.deepcopy(cp_Board)
    
    return


N=int(input())
board = []
maxBlock=0
for _ in range(N):
    l=list(map(int, input().split()))
    board.append(l)
dfs(0)
print(maxBlock)