# 14503 <로봇 청소기>

import sys

input = lambda: sys.stdin.readline()

move = (-1, 0, 1, 0), (0, 1, 0, -1) # 북->동->남->서

def solution(r,c,d):
    
    count = 0
    while 1:
        i=0 # 방향을 전부 돌았는지 확인
        if board[r][c] == 0:
            board[r][c] = 2 #청소 끝
            count+=1
        elif board[r][c] == 1:
            break
        condition = False
        for i in range(0, 4):
            # 로봇의 방향을 왼쪽으로 바꿈
            if d==0:
                d = 3
            else:
                d = d-1

            if 0<=r+move[0][d]<N and 0<=c+move[1][d]<M and board[r+move[0][d]][c+move[1][d]] == 0:
                # 아직 청소를 하지 않은 곳인지 파악
                (r,c) = (r+move[0][d], c+move[1][d])
                condition = True
                break
            else:
                continue
        if i == 3 and condition == False:
            # 네방향 모두 청소가 되어 있거나 벽인경우
            if 0<=r-move[0][d]<N and 0<=c-move[1][d]<M:
                # 후진
                (r,c) = (r-move[0][d], c-move[1][d])
            else:
                break
    print(count)
    return


if __name__ == "__main__":

    N, M = list(map(int, input().split()))
    r, c, d = list(map(int, input().split()))
    board = []

    for _ in range(N):
        l = list(map(int, input().split()))
        board.append(l)
    solution(r, c, d)