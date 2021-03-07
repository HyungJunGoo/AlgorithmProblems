# 1753 번 최단 경로
import sys
from collections import deque

class Graph:

    def __init__(self, V):
        self.V = V
        self.n_graph = {}
        for v in range(1, V+1):
            self.n_graph[v] = dict()

    def minDistance(self, dist, search_dq):
        min_d = 20001
        min_index = None
        for v in search_dq:
            if dist[v] < min_d:
                min_d = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src):
        dist = [20001] * (self.V + 1)
        dist[src] = 0
        sptSet = [False] * (self.V+1)
        search_dq = deque()
        search_dq.append(src)
        for _ in range(1, self.V + 1):
            u = self.minDistance(dist, search_dq)
            if u == None: # 더 이상 방문할 곳 없음
                break
            search_dq.remove(u)
            for v in self.n_graph[u].keys():
                search_dq.append(v)
                if dist[v] > dist[u] + self.n_graph[u][v]:
                    dist[v] = dist[u] + self.n_graph[u][v]

        self.printSolution(dist)

    def printSolution(self, dist):
        for i,d in enumerate(dist):
            if i == 0: continue
            if d == 20001:
                print("INF")
            else: print(d)
        return

def main():
    V,E = [int(x) for x in sys.stdin.readline().split()]
    src = int(sys.stdin.readline())
    g = Graph(V)
    for _ in range(E):
        u, v, w = [int(x) for x in sys.stdin.readline().split()]
        g.n_graph[u][v] = w
    g.dijkstra(src)
    
    return
if __name__ == "__main__":
    main()