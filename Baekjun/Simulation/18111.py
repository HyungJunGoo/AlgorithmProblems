from collections import defaultdict
import sys

input = lambda: sys.stdin.readline()


def solution(N, M, B, board):
    h_to_n = defaultdict(int)
    result = []
    for i in range(N):
        for j in range(M):
            h_to_n[board[i][j]] += 1
    h_list = sorted(list(h_to_n.keys()), reverse=True)
    for hx in range(max(h_to_n.keys()), -1, -1):
        t, inven = 0, B
        for hn in h_list:
            if hn < hx:
                t += (hx - hn) * h_to_n[hn]
                inven -= (hx - hn) * h_to_n[hn]
            elif hn > hx:
                t += 2 * (hn - hx) * h_to_n[hn]
                inven += (hn - hx) * h_to_n[hn]
        if inven >= 0:
            result.append([t, hx])
    result.sort(key=lambda x: (x[0], -x[1]))
    print(*result[0])


if __name__ == "__main__":
    N, M, B = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(N)]

    solution(N, M, B, board)
