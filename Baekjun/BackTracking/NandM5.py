import sys
from itertools import permutations

def main():
    N, M = [int(x) for x in sys.stdin.readline().split()]
    numbers = [int(x) for x in sys.stdin.readline().split()]
    numbers.sort()
    p = permutations(numbers, M)
    for c in list(p):
        for n in c:
            print(n, end=" ")
        print()
    return

if __name__ == "__main__":
    main()