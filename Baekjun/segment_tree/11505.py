
# 11505 구간 곱 구하기

import sys
from math import *

input = lambda: sys.stdin.readline()

MOD = 1000000007

# def initTree(node, start, end):
#     if start == end:
#         STree[node] = numbers[start] % MOD
#         return STree[node]
#     mid = (start+end)//2
#     STree[node] = (initTree(node*2, start, mid) * initTree(node*2+1, mid+1, end))%MOD
#     return STree[node]

def updateTree(node, start, end, index, diff):
    if index < start or index > end: return
    if start==end:
        STree[node]=diff
        return
    mid = (start+end)//2
    updateTree(node*2, start, mid, index, diff)
    updateTree(node*2+1, mid+1, end, index, diff)
    STree[node] = (STree[node*2] * STree[node*2+1]) % MOD
    
def mulFind(node, start, end, left, right):
    if right < start or left > end:
        return 1
    if left <= start and right >= end:
        return STree[node]
    mid = (start+end)//2
    return (mulFind(node*2, start, mid, left, right)*mulFind(node*2+1, mid+1, end, left, right))%MOD

def solution(numbers, N, M, K):

    for i in range(N):
        updateTree(1, 0, N-1, i, numbers[i])

    for _ in range(M+K):
        a, b, c = list(map(int, input().split()))
        if a == 1:
            numbers[b-1] = c
            updateTree(1, 0, N-1, b-1, c)
        elif a == 2:
            print(mulFind(1, 0, N-1, b-1, c-1))
    return

if __name__ == "__main__":
    N, M, K = list(map(int, input().split()))
    numbers = []
    h = int(ceil(log2(N)))
    t_size = 1<<h+1
    STree = [0] * t_size
    for _ in range(N):
        numbers.append(int(input()))
    solution(numbers, N, M, K)