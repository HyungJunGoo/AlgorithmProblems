# <1717> 집합의 표현

import sys
sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline()

def get_parent(d, a):
	if d[a] == a:
		return a
	d[a] = get_parent(d, d[a])
	return d[a]

def function(a, b):
	p_a, p_b = get_parent(d, a), get_parent(d, b)

	if p_a < p_b:
		d[p_b] = d[p_a]
	elif p_b < p_a:
		d[p_a] = d[p_b]

N,M = list(map(int, input().split()))
d = {i : i for i in range(N+1)}
for _ in range(M):
	x, a, b = list(map(int, input().split()))
	if x == 0:
		function(a, b)
	else:
		if get_parent(d, a) != get_parent(d, b):
			print("NO")
		else:
			print("YES")
