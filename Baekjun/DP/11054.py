# 11054 <가장 긴 바이토닉 부분수열>
# https://www.acmicpc.net/problem/11054

import sys
from copy import copy
from bisect import bisect_left

input = lambda: sys.stdin.readline()

def LIS(arr, n):
    subarr = []
    tmp = []
    for i in range(n):
        if i==0:
            tmp.append(arr[i])
        else:
            if tmp[-1] < arr[i]:
                tmp.append(arr[i])
            else:
                idx=bisect_left(tmp, arr[i])
                tmp[idx] = arr[i]
                subarr.append(idx+1)
                continue
        subarr.append(len(tmp))
    return subarr

def solution():
    n = int(input())
    arr = list(map(int, input().split()))
    r_dp = LIS(arr, n)
    rev_arr = copy(arr)
    rev_arr.reverse()
    l_dp = LIS(rev_arr, n)
    l_dp.reverse()
    print(max([r_dp[i]+l_dp[i]-1 for i in range(n)]))
    return
solution()