# 2268

import sys, math
input = lambda : sys.stdin.readline()

N,M = list(map(int, input().split()))
h = math.ceil(math.log2(N))
tree = [0 for _ in range(1<<(h+1))]
numbers = [0 for _ in range(N)]

def init(node, start, end):
    if start == end:
        tree[node] = numbers[start]
        return tree[node]
    tree[node] = init(node*2, start, (start+end)//2) + init(node*2+1, (start+end)//2+1, end)
    return tree[node]

def get_sum(node, start, end, left, right):

    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]
    return get_sum(node*2, start, (start+end)//2, left, right) + get_sum(node*2+1, (start+end)//2+1, end, left, right)

def update(node, start, end, index, diff):

    if index > end or index < start:
        return
    tree[node] += diff
    if start != end:
        update(node*2, start, (start+end)//2, index, diff)
        update(node*2+1, (start+end)//2+1, end, index, diff)
    return

init(1, 0, N-1)
for _ in range(M):
    i,j,k = list(map(int, input().split()))
    if i == 0:#sum
        if j>k:
            (j,k) = (k,j)
        print(get_sum(1, 0, N-1, j-1, k-1))

    else:
        diff = k-numbers[j-1]
        numbers[j-1] = k
        update(1, 0, N-1, j-1, diff)

sys.exit()