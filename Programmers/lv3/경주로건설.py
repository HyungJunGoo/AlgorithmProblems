# <경주로 건설>
# 2020 카카오 인턴
from collections import deque

di = [-1, 1, 0, 0], [0, 0, 1, -1]  # 위 아래 오른쪽 왼쪽


def solution(board):
    N = len(board)
    dp = [[10 ** 10 for _ in range(N)] for _ in range(N)]
    q = deque()
    q.append(((0, 0), 0, -1))  # 위치, 비용, 바라보는 방향
    answer = 10 ** 10
    while len(q):
        (i, j), cost, heading = q.popleft()
        if i == N - 1 and j == N - 1:
            answer = min(answer, cost)
        for n in range(4):
            n_i, n_j = i + di[0][n], j + di[1][n]
            if (
                (n_i >= 0 and n_i < N)
                and (n_j >= 0 and n_j < N)
                and board[n_i][n_j] == 0
            ):
                add_cost = 100 if heading == n or heading == -1 else 600
                if dp[n_i][n_j] < cost + add_cost - 400:
                    continue
                dp[n_i][n_j] = cost + add_cost
                q.append(((n_i, n_j), cost + add_cost, n))

    return answer


board = [[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]
board2 = [
    [0, 0, 0, 0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 1],
    [0, 0, 1, 0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 0],
]
board3 = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 0],
    [0, 0, 1, 0, 0, 0],
    [1, 0, 0, 1, 0, 1],
    [0, 1, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0],
]
answer = solution(board2)

board4 = [[0, 0], [0, 0]]
assert solution(board4) == 700

board5 = [
    [0, 0, 0, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 1, 1, 1, 0],
    [1, 0, 0, 1, 0, 0, 0, 0],
    [1, 1, 0, 0, 0, 1, 1, 1],
    [1, 1, 1, 1, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 1, 1, 0],
    [1, 1, 1, 1, 1, 1, 1, 0],
    [1, 1, 1, 1, 1, 1, 1, 0],
]

print(solution(board5))
# assert solution(board5) == 4500
