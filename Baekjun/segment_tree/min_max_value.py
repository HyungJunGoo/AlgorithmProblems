# 2357
import sys

MAX_VALUE = 1000000001
MIN_VALUE = -1
def min_init(node, start, end):
    if start == end:
        min_tree[node] = numbers[start]
        return min_tree[node]
    mid = (start+end)//2
    min_tree[node] = min(min_init(node*2, start, mid), min_init(node*2+1, mid+1, end))
    return min_tree[node]

def max_init(node, start, end):
    if start == end:
        max_tree[node] = numbers[start]
        return max_tree[node]
    mid = (start+end)//2
    max_tree[node] = max(max_init(node*2, start, mid), max_init(node*2+1, mid+1, end))
    return max_tree[node]

numbers = []
min_tree = [0] * 3000000
max_tree = [0] * 3000000

def min_find(node, start, end, left, right):
    if right < start or left > end:
        return MAX_VALUE

    if left<=start and right >= end:
        return min_tree[node]
    
    mid = (start+end)//2
    return min(min_find(node*2, start, mid, left, right), min_find(node*2+1, mid+1, end, left, right))

def max_find(node, start, end, left, right):
    if right < start or left > end:
        return MIN_VALUE

    if left <= start and right >= end:
        return max_tree[node]
    mid = (start+end)//2
    return max(max_find(node*2, start, mid, left, right), max_find(node*2+1, mid+1, end, left, right))


def main():
    l = input().split()
    N, M = int(l[0]), int(l[1])

    for i in range(N):
        numbers.append(int(sys.stdin.readline()))
    min_init(1, 0, N-1)
    max_init(1, 0, N-1)

    for i in range(M):
        a, b = [int(x) for x in sys.stdin.readline().split()]
        print(min_find(1, 0, N-1, a-1, b-1), end= ' ')
        print(max_find(1, 0, N-1, a-1, b-1))
        
    return

if __name__ == "__main__":
    main()
    