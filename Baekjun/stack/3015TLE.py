# 3015 오아시스 재결합
# 시간초과 풀이
import sys
import heapq as hq

input = lambda: sys.stdin.readline()

def solution(N, numbers):
    answer = 0
    heap = [] # maxHeap
    for i in range(N):
        hq.heappush(heap, [-numbers[i], i])
    checked_h = {i:False for i in range(N)}
    while len(heap)>0:
        if i == 0:
            answer += (N-1) - heap[0][1] # 마지막 사람까지 수
            checked_h[heap[0][1]] = True
            hq.heappop(heap)
        else:
            checked_h[heap[0][1]] = True
            for j in range(heap[0][1]+1, N):
                answer += 1
                if checked_h[j] == True:
                    break
            hq.heappop(heap)

    print(answer)
    return
if __name__ == "__main__":
    N = int(input())
    numbers = [int(input()) for _ in range(N)]
    solution(N, numbers)