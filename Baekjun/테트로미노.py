# 14500번

import sys

N, M = list(map(int, sys.stdin.readline().split()))
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

def main():

    val = 0

    for j in range(N):
        for i in range(M-1):
            s = board[j][i] + board[j][i+1]
            val = max(val, s+sumOfTetro(i-1, j, i+2, j))
            val = max(val, s+sumOfTetro(i, j-1, i+1, j+1))
            val = max(val, s+sumOfTetro(i+1, j-1, i, j+1))
            val = max(val, s+sumOfTetro(i-1, j+1, i, j+1))
            val = max(val, s+sumOfTetro(i, j+1, i+1, j+1))
            val = max(val, s+sumOfTetro(i+1, j+1, i+2, j+2))
    
    for j in range(N):
        for i in range(M-2):
            s = board[j][i] + board[j][i+1] + board[j][i+2]
            val = max(val, s+sumOfTetro(i, j-1, -1, -1))
            val = max(val, s+sumOfTetro(i+1, j-1, -1, -1))
            val = max(val, s+sumOfTetro(i+2, j-1, -1, -1))
            val = max(val, s+sumOfTetro(i, j+1, -1, -1))
            val = max(val, s+sumOfTetro(i+1, j+1, -1, -1))
            val = max(val, s+sumOfTetro(i+2, j+1, -1, -1))

    for j in range(N-2):
        for i in range(M):
            s = board[j][i] + board[j+1][i] + board[j+2][i]
            val = max(val, s+sumOfTetro(i-1, j, -1, -1))
            val = max(val, s+sumOfTetro(i+1, j, -1, -1))
            val = max(val, s+sumOfTetro(i-1, j+1, -1, -1))
            val = max(val, s+sumOfTetro(i+1, j+1, -1, -1))
            val = max(val, s+sumOfTetro(i-1, j+2, -1, -1))
            val = max(val, s+sumOfTetro(i+1, j+2, -1, -1))
            val = max(val, s+sumOfTetro(i, j+3, -1, -1))
    print(val)
    return

def sumOfTetro(a_x, a_y, b_x, b_y):
    s = 0
    if a_x < 0 or a_x >= M or a_y < 0 or a_y >= N:
        pass
    else:
        s += board[a_y][a_x]
    if b_x < 0 or b_x >= M or b_y < 0 or b_y >= N:
        pass
    else:
        s += board[b_y][b_x]
    
    return s

if __name__ == "__main__":
    main()