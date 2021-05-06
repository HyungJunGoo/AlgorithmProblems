# 11437 <LCA>
# Not Solved

import sys
from collections import defaultdict
from collections import deque

input = lambda : sys.stdin.readline()
N = int(input())
def node_pairs():
    return [[],[]]
g = defaultdict(node_pairs)
def add_node(parent,child):
    g[parent][1].append(child)
    g[child][0].append(parent)
add_node(0,1)
q = deque()
for _ in range(N-1):
    a,b = list(map(int, input().split()))
    q.append((a,b))
    
while len(q):
    a,b = q.popleft()
    if len(g[a][0]) > 0 : # a is parent 
        add_node(a, b)
    elif len(g[b][0]) > 0: # b is parent
        add_node(b,a)
    else:
        print(f"\n{a}, {b} dont know who is parent")
        q.append((a,b))

def get_CA(x,y):
    l1, l2 = set(), set()
    l1.add(x)
    l2.add(y)
    while True:
        # print(f"l1 : {l1}\nl2: {l2}")
        p_x = g[x][0][0]
        p_y = g[y][0][0]
        if p_x == p_y:
            return p_x
        l1.add(p_x)
        l2.add(p_y)
        if p_x in l2:
            return p_x
        if p_y in l1:
            return p_y
        if x != 1: 
            x = p_x
        if y != 1:
            y = p_y
    return
M = int(input())
result = []
for _ in range(M):
    x,y = list(map(int, input().split()))
    ca = get_CA(x,y)
    result.append(ca)
for ca in result:
    print(ca)