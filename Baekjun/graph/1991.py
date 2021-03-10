# 1991 <트리순회>

import sys
input = lambda: sys.stdin.readline()

def preorder(P):
    if P == '.':
        return
    print(P,end="")
    preorder(t[P][0])
    preorder(t[P][1])
    return

def inorder(P):
    if P == '.':
        return
    inorder(t[P][0])
    print(P,end="")
    inorder(t[P][1])
    return

def postorder(P):
    if P == '.':
        return
    postorder(t[P][0])
    postorder(t[P][1])
    print(P,end="")
    return

if __name__ == "__main__":
    N = int(input())
    t = {} 
    for _ in range(N):
        P,L,R = list(input().split())
        t[P] = [L,R]
    preorder('A')
    print()
    inorder('A')
    print()
    postorder('A')
    print()