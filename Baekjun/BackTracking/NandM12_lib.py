from itertools import combinations_with_replacement
import sys

def main():
    N, M = map(int, sys.stdin.readline().split())
    numbers = list(map(int, sys.stdin.readline().split()))
    numbers.sort()
    numbers = list(combinations_with_replacement(numbers, M))
    numbers = sorted(list(set(numbers)))
    for n in numbers:
        print(*n)
    return

if __name__ == "__main__":
    main()