import sys
import bisect
def main():
    N = int(input())
    numbers = [int(x) for x in sys.stdin.readline().split()]
    M = int(input())
    find_numbers = [int(x) for x in sys.stdin.readline().split()]

    numbers.sort()
    for n in find_numbers:
        i = bisect.bisect_left(numbers, n)
        if i == N:
            print(0)
        elif numbers[i] == n:
            print(1)
        else: print(0)

    return
if __name__ == "__main__":
    main()
