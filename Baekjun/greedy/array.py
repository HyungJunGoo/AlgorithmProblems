# https://www.acmicpc.net/problem/1080

import sys

def change(arr1, x, y):
    for i in range(x, x+3):
        for j in range(y, y+3):
            arr1[i][j] = 1 - arr1[i][j]
    return arr1

def main():
    N, M = map(int, sys.stdin.readline().split())
    arr1 = [[0 for _ in range(M)] for _ in range(N)]
    arr2 = [[0 for _ in range(M)] for _ in range(N)]
    
    for i in range(N):
        n = sys.stdin.readline()
        for j in range(M):
            arr1[i][j] += int(n[j])
    for i in range(N):
        n = sys.stdin.readline()
        for j in range(M):
            arr2[i][j] += int(n[j])
    count = 0
    for i in range(N-2):
        for j in range(M-2):
            if arr1[i][j] != arr2[i][j]:
                arr1 = change(arr1,i,j)
                count += 1
    for i in range(N):
        for j in range(M):
            if arr1[i][j] != arr2[i][j]:
                print("-1")
                return
    print(count)
    return

if __name__ == "__main__":
    main()