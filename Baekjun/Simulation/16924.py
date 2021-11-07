# https://www.acmicpc.net/problem/16924

from collections import defaultdict
import sys

input = lambda: sys.stdin.readline()


def get_check_list(i, x, y):
    result = []
    result.append((x, y))
    for _y in range(1, i + 1):
        result.append((x, y + _y))
        result.append((x, y - _y))
    for _x in range(1, i + 1):
        result.append((x + _x, y))
        result.append((x - _x, y))

    return result


def solution(N, M, board):
    mark = defaultdict()
    for i in range(N):
        for j in range(M):
            if board[i][j] == "*":
                mark[(i, j)] = True
    _N = N if N % 2 == 1 else N - 1
    _M = M if M % 2 == 1 else M - 1
    size = min(_N, _M) // 2
    result = []

    for i in range(size, 0, -1):
        for y in range(i, N - i):
            for x in range(i, M - i):
                check_lists = get_check_list(i, x, y)
                available = True
                _to_mark = []
                for check_list in check_lists:
                    if not available:
                        break
                    _x, _y = check_list
                    if _x >= 0 and _x < M and _y >= 0 and _y < N:
                        if board[_y][_x] == "*":
                            _to_mark.append((_y, _x))
                        elif board[_y][_x] == ".":
                            available = False
                if available:
                    for _y, _x in _to_mark:
                        mark[(_y, _x)] = False
                    result.append([y + 1, x + 1, i])

    if any(mark.values()):
        return -1

    return result


if __name__ == "__main__":

    N, M = map(int, input().split())
    board = [[x for x in input().split()[0]] for _ in range(N)]

    result = solution(N, M, board)
    if result == -1:
        print(result)
    else:
        print(len(result))
        for _result in result:
            print(*_result)
