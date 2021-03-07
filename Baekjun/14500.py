import sys

input = lambda : sys.stdin.readline()

N, M = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(N)]

testCase = [
    [(1, 0), (0, 1), (1, 1)],
    [(0, 1), (0, 2), (0, 3)],
    [(1, 0), (2, 0), (3, 0)],
    [(1, 0), (0, 1), (0, 2)],
    [(0, 1), (0, 2), (-1, 2)],
    [(1, 0), (1, 1), (1, 2)],
    [(0, 1), (0, 2), (1, 2)],
    [(1, 0), (2, 0), (2, 1)],
    [(0, 1), (1, 1), (2, 1)],
    [(1, 0), (2, 0), (0, 1)],
    [(1, 0), (2, 0), (2, -1)],
    [(1, 0), (1, 1), (2, 1)],
    [(1, 0), (-1, 1), (0, 1)],
    [(0, 1), (1, 0), (1, -1)],
    [(0, 1), (1, 1), (1, 2)],
    [(0, 1), (1, 1), (0, 2)],
    [(1, 0), (1, -1), (1, 1)],
    [(1, 0), (2, 0), (1, -1)],
    [(1, 0), (2, 0), (1, 1)]
]

def main():
    val = 0
    for i in range(N):
        for j in range(M):
            val = max(val, sumOfTetro(i,j))
    print(val)
    return

def sumOfTetro(i, j):
    result = 0
    for tc in range(len(testCase)):
        sumOftc = board[i][j]
        for d in range(3):
            x = testCase[tc][d][0]
            y = testCase[tc][d][1]
            if 0 <= i+y < N and 0 <= j+x < M:
                sumOftc += board[i+y][j+x]
            else:
                break
        result = max(result, sumOftc)
    return result

if __name__ == "__main__":
    main()
