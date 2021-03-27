# 19237 <어른 상어>

from collections import deque
import sys

input = lambda: sys.stdin.readline()
di = (-1,1,0,0), (0,0,-1,1)

def solution():
    global q, b2
    t = 0
    while t <= 1000:
        t+=1
        nextq = deque()
        newly1 = [] #원래 비어있던 공간 체크
        for row in range(N):
            for col in range(N):
                if b2[row][col][0] == 0 and b2[row][col][1][0] == 0 and b2[row][col][1][1] == 0:
                    newly1.append([row, col])
        while q:
            i, j, d = q.popleft()
            num = b2[i][j][0]
            move = False
            new_i, new_j, new_d = -1,-1,-1
            prefer_arr = prefer[num]
            for nd in prefer_arr[d-1]:
                ni, nj = i + di[0][nd-1], j + di[1][nd-1]
                if ni >= 0 and ni < N and nj>=0 and nj < N:
                    if b2[ni][nj][0] == 0 and b2[ni][nj][1][0] == 0 and b2[ni][nj][1][1] == 0:
                        b2[ni][nj][0] = num
                        b2[ni][nj][1] = [num, K]
                        b2[i][j][0] = 0
                        move = True
                        newly1.append([ni, nj])
                        new_i, new_j, new_d = ni, nj, nd
                        break
                    # 다른 상어 있는데 Z=K인지 확인 (이번 횟수에 넘어온 상어인지)
                    elif b2[ni][nj][0] != 0 and b2[ni][nj][1][1] == K and [ni,nj] in newly1:
                        if b2[ni][nj][0] > num : #쫓아냄
                            for idx in range(len(nextq)):
                                ii, jj, dd = nextq[idx]
                                if ii==ni and jj ==nj:
                                    nextq[idx][2] = nd

                        b2[ni][nj][0], b2[ni][nj][1][0] = min(num, b2[ni][nj][0]) , min(num, b2[ni][nj][0]) 
                        b2[i][j][0] = 0
                        move = True
                        break
            if move == False:
                prefer_arr = prefer[num]
                for nd in prefer_arr[d-1]:
                    ni, nj = i + di[0][nd-1], j + di[1][nd-1]
                    if ni >= 0 and ni < N and nj>=0 and nj < N:
                        if b2[ni][nj][0] == 0 and b2[ni][nj][1][0]==num:
                            b2[ni][nj][0] = num
                            b2[ni][nj][1] = [num, K]
                            b2[i][j][0] = 0
                            move = True
                            new_i, new_j, new_d = ni, nj, nd
                            break
            
            if move == False:
                nextq.append([i,j,d])
            else:
                if new_i != -1 and new_j != -1 and new_d != -1:
                    if [new_i, new_j, new_d] not in nextq:
                        nextq.append([new_i, new_j, new_d])
        q = nextq
        for row in range(N):
            for col in range(N):
                if b2[row][col][0] == 0 and b2[row][col][1][0] != 0:
                    b2[row][col][1][1] -= 1
                    if b2[row][col][1][1] == 0:
                        b2[row][col][1][0] = 0   
        
        if len(q) == 1:
            break
    if t > 1000:
        print(-1)
    
    else:
        print(t)

    return


if __name__ == "__main__":
    # N: 격자 크기 , M: 상어 수, K: 냄새 카운트
    N, M, K = list(map(int, input().split()))
    b1 = [list(map(int, input().split())) for _ in range(N)]
    b2 = []
    q = deque()
    init_d = list(map(int, input().split()))
    for i in range(N):
        tmp_l = []
        for j in range(N):
            if b1[i][j] > 0:
                tmp_l.append([b1[i][j], [b1[i][j], K]])
                q.append([i, j, init_d[b1[i][j] - 1]])
            else:
                tmp_l.append([0, [0, 0]])
        b2.append(tmp_l)
    
    prefer = dict()

    for i in range(1, M+1):
        prefer[i] = []
        for _ in range(4):
            prefer_l = list(map(int, input().split()))
            prefer[i].append(prefer_l)
    
    solution()