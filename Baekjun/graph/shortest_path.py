import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize
V,E = map(int, input().split())

# 시작점
K = int(input())

dp = [INF] * (V+1)
heap = []
graph = [[] for _ in range(V+1)]

def dijkstra(start):
    dp[start] = 0

    heapq.heappush(heap, (0, start))

    while heap:
        w, node = heapq.heappop(heap)

        if dp[node] < w:
            continue
        
        for next_w, next_node in graph[node]:
            next_wei = w + next_w
            if next_wei < dp[next_node]:
                dp[next_node] = next_wei
                heapq.heappush(heap,(next_wei, next_node))

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((w,v))

dijkstra(K)

for i in range(1, V+1):
    print("INF" if dp[i] == INF else dp[i])