# https://www.acmicpc.net/problem/17609

import sys
from collections import deque

input = lambda: sys.stdin.readline()


def isPalindrome(words):
    result = []
    for word in words:
        if word == word[::-1]:
            result.append(0)

        else:
            left, right = 0, len(word) - 1
            check = 0
            q = deque()
            q.append((left, right, check))
            semi_palindrome = False
            while len(q):
                left, right, check = q.popleft()
                if check >= 2:
                    continue
                if left == right or left > right:
                    if check < 2:
                        semi_palindrome = True
                        q.clear()
                        continue
                if word[left] != word[right]:
                    if word[left + 1] == word[right]:
                        q.append((left + 1, right, check + 1))
                    if word[left] == word[right - 1]:
                        q.append((left, right - 1, check + 1))
                    if not (
                        word[left + 1] == word[right] or word[left] == word[right - 1]
                    ):
                        q.append((left, right, check + 2))
                else:
                    q.append((left + 1, right - 1, check))
            if semi_palindrome:
                result.append(1)
            else:
                result.append(2)

    return result


if __name__ == "__main__":
    n = int(input())
    words = [word for word in [input().split()[0] for _ in range(n)]]
    for word in isPalindrome(words):
        print(word)
