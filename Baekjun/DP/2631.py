import sys

input = lambda: sys.stdin.readline()


def solution(nums):
    lis = []

    def _binary_search(n):
        start, end = 0, len(lis) - 1
        if n > lis[end]:
            lis.append(n)
            return
        while start <= end:
            if start == end:
                if lis[start] > n:
                    lis[start] = n
                break
            if start + 1 == end:
                if lis[start] > n:
                    lis[start] = n
                else:
                    lis[end] = n
                break
            mid = (start + end) // 2
            if lis[mid] < n:
                start = mid + 1
            else:
                end = mid

    for n in nums:
        if len(lis) == 0:
            lis.append(n)
            continue
        _binary_search(n)
    return len(nums) - len(lis)


if __name__ == "__main__":
    n = int(input())
    nums = [int(input()) for _ in range(n)]
    print(solution(nums))
