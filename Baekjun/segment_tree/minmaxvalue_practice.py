
import sys

input = lambda: sys.stdin.readline()


N, M = list(map(int, input().split()))
numbers = [int(input()) for _ in range(N)]

minTree = [0] * 400000
    

def init_minTree(node, start, end):
    if start == end:
        minTree[node] = numbers[start]
        return minTree[node]
    mid = (start+end)//2
    minTree[node] = min(init_minTree(node*2, start, mid), init_minTree(node*2+1, mid+1, end))
    return minTree[node]

def find_min(node, start, end, left, right):
    if left > end or right < start:
        return 1000000001
    if left <= start and right >= end:
        return minTree[node]
    mid = (start+end)//2
    return min(find_min(node*2, start, mid, left, right), find_min(node*2+1, mid+1, end, left, right))

if __name__ == "__main__":
    init_minTree(1, 0, N-1)
    for _ in range(M):
        a, b = list(map(int, input().split()))
        print(find_min(1, 0, N-1, a-1, b-1))
