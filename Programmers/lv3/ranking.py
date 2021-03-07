
class Node:
    def __init__(self, n):
        self.number = n
        self.in_node = []
        self.out_node = []

class Graph:
    def __init__(self, v):
        self.V = v
        self.graph = []
        for i in range(1, self.V+1):
            self.graph.append(Node(i))

def dfs_in_node(g, i, visited):
    if i in visited:
        return visited
    visited.append(i)        
    for n in g.graph[i-1].in_node:
        visited = dfs_in_node(g, n, visited)
    return visited

def dfs_out_node(g, i, visited):
    if i in visited:
        return visited
    visited.append(i)        
    for n in g.graph[i-1].out_node:
        visited = dfs_out_node(g, n, visited)
    return visited

def solution(n, results):
    answer = 0
    g = Graph(n)

    for result in results:
        A = result[0]
        B = result[1]
        g.graph[A-1].out_node.append(B)
        g.graph[B-1].in_node.append(A)

    for i in range(1, n+1):
        visited = []
        visited = dfs_in_node(g, i, visited)
        visited.remove(i)
        n_in = len(visited)
        visited = []
        visited = dfs_out_node(g, i, visited)
        visited.remove(i)
        n_out = len(visited)
        if n_in+n_out == n-1:
            answer += 1
        # print(f"n_in:{n_in}, n_out:{n_out}")
    # print(g.graph[0].out_node)
    
    # print(g.graph[2].number)

    return answer

solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]])