# <경주로 건설>
# 2020 카카오 인턴
from collections import deque
di = [-1,1,0,0], [0,0,1,-1] # 위 아래 오른쪽 왼쪽
def solution(board):
    N = len(board)
    dp = [[10**6 for _ in range(N)] for _ in range(N)]
    q = deque()
    q.append(((0,0), 0, None)) # 위치, 비용, 바라보는 방향
    while len(q):
        top = q.popleft()
        i, j = top[0]
        cost = top[1]
        heading = top[2]
        if i == N-1 and j == N-1:
            # answer = min(answer, cost)
            continue
        for n in range(4):
            n_i, n_j = i+di[0][n], j+di[1][n]
            if n_i == 0 and n_j == 0:
                continue
            if (n_i >= 0 and n_i < N) and (n_j >= 0 and n_j < N):
                if board[n_i][n_j] == 0:
                    if heading == None:
                        q.append(((n_i, n_j), cost+100, n))
                    if heading != None and heading != n:
                        if heading == 0:
                            if n != 1:
                                if dp[n_i][n_j] >= cost + 600:
                                    dp[n_i][n_j] = cost + 600
                                    q.append(((n_i,n_j), cost + 600, n))
                        elif heading == 1:
                            if n != 0:
                                if dp[n_i][n_j] >= cost + 600:
                                    dp[n_i][n_j] = cost + 600
                                    q.append(((n_i,n_j), cost + 600, n))
                        elif heading == 2:
                            if n != 3:
                                if dp[n_i][n_j] >= cost + 600:
                                    dp[n_i][n_j] = cost + 600
                                    q.append(((n_i,n_j), cost + 600, n))
                        elif heading ==3:
                            if n != 2:
                                if dp[n_i][n_j] >= cost + 600:
                                    dp[n_i][n_j] = cost + 600
                                    q.append(((n_i,n_j), cost + 600, n))
                    elif heading != None and heading == n:
                        if dp[n_i][n_j] >= cost + 100:
                            dp[n_i][n_j] = cost + 100
                            q.append(((n_i, n_j), cost+100, n))
    return dp[N-1][N-1]

board = [[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]
board2 = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]
board3 = [[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]
answer = solution(board2)
print(answer)