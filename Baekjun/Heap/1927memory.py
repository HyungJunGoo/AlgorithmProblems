# 1927 <최소 힙>

import sys
sys.setrecursionlimit(1000000)

input = lambda: sys.stdin.readline()

h = [0,0]
h_size = 1

def insertHeap(i, n):
    global h_size
    if i>h_size : # leaf
        h.extend([0])
        h[i] = n
        h_size +=1
        return
    if h[i] == 0:
        h[i] = n
        return
    if h[i] > n:
        copy_h = h[i]
        h[i] = n
        insertHeap(i+1, copy_h)
    else: # 원래 위치의 값보다 n 이 더 크거나 같다
        insertHeap(i+1, n)
    return

def minHeap():
    global h_size
    if h_size == 0:
        print(0)
        return
    
    print(h[1])
    for i in range(1,h_size):
        h[i] = h[i+1]
    h.pop()
    h_size-=1
    return


def solution():
    N = int(input())
    for _ in range(N):
        n = int(input())
        if n==0:
            minHeap()
        else:
            insertHeap(1, n)
    return


if __name__ == "__main__":
    solution()