# DFS 가능
# itertools.combinations_with_replacement로 쉽게 풀이도 가능
import sys
from copy import copy
from itertools import permutations

answer = []

def main():
    N, M = [int(x) for x in sys.stdin.readline().split()]
    numbers = [int(x) for x in sys.stdin.readline().split()]
    numbers.sort()
    numSet = list(set(numbers))
    for n in numSet:
        cur_list = [n]
        DFS(1, cur_list, numSet, M)
        cur_list.pop()
    for ans in answer:
        for n in ans:
            print(n, end=" ")
        print()
    return

def DFS(cnt, cur_list, numSet, M):
    if cnt == M:
        copy_list = copy(cur_list)
        copy_list.sort()
        if copy_list not in answer:
            answer.append(copy_list)
        return
    for n in numSet:
        cur_list.append(n)
        DFS(cnt+1, cur_list, numSet, M)
        cur_list.pop()


if __name__ == "__main__":
    main()