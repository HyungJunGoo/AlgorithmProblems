# 1628 <곱셈>

import sys
sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline()

A,B,C = list(map(int, input().split()))

def divide(i):
    if i == 0:
        return 1
    num = divide(i//2)
    num2 = (num*num)%C
    if i % 2 == 1:
        return (num2*A)%C
    return num2

print(divide(B))