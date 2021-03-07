# 3015 오아시스 재결합
# Stack

import sys
from collections import deque

input = lambda: sys.stdin.readline()

def solution(N, numbers):
    st = deque()
    result = 0

    for i in range(N):
        count = 1 # 같은 키 체크
        while len(st) != 0:
            if st[len(st)-1][0] < numbers[i]:
                result += st[len(st)-1][1]
                st.pop()
            elif st[len(st)-1][0] == numbers[i]:
                result += st[len(st)-1][1]
                count = st[len(st)-1][1] + 1
                st.pop()
            else:
                result += 1
                break
        st.append([numbers[i], count])
    print(result)
    return

if __name__ == "__main__":
    N = int(input())
    numbers = [int(input()) for _ in range(N)]
    solution(N, numbers)