# 17144 <미세먼지 안녕!>
from collections import deque
import sys

input = lambda: sys.stdin.readline()
di = [-1,1,0,0], [0,0,-1,1]

def solution():
	t = 0
	while t < T:
		t += 1
		q = deque()
		for r in range(R):
			for c in range(C):
				if b[r][c] > 0:
					s = b[r][c] // 5
					n = 0
					for idx in range(4):
						nr, nc = r+di[0][idx], c+di[1][idx]
						if nr >= 0 and nr < R and nc >=0 and nc < C and b[nr][nc] != -1:
							n+=1
							q.append((nr, nc, s))
					b[r][c] -= n*s
		while q:
			x,y,ss = q.popleft()
			b[x][y] += ss
		# 공기 청정기
		for n in range(len(u_l)-1):
			x,y = u_l[n][0], u_l[n][1]
			b[x][y] = b[u_l[n+1][0]][u_l[n+1][1]]
		b[u_l[len(u_l)-1][0]][u_l[len(u_l)-1][1]] = 0

		for n in range(len(d_l)-1):
			x,y = d_l[n][0], d_l[n][1]
			b[x][y] = b[d_l[n+1][0]][d_l[n+1][1]]
		b[d_l[len(d_l)-1][0]][d_l[len(d_l)-1][1]] = 0
	# for l in b:
	# 	print(l)
	return get_m()

def get_m():
	result = 0
	for r in range(R):
		for c in range(C):
			if b[r][c] > 0:
				result += b[r][c] 
	return result


R,C,T = list(map(int, input().split()))

b = []
for _ in range(R):
	b.append(list(map(int, input().split())))
ac_u = 0
ac_d = 0
for r in range(R):
	if b[r][0] == -1:
		if ac_u == 0:
			ac_u+=r
		else:
			ac_d+=r
u_cnt = (ac_u + 1 - 2 + C)*2-1
d_cnt = (R-ac_d - 2 + C)*2-1
u_l = []
d_l = []
for i in range(ac_u-1, -1, -1):
	u_l.append([i, 0])
for i in range(1,C):
	u_l.append([0, i])
for i in range(1, ac_u+1):
	u_l.append([i, C-1])
for i in range(C-2, 0, -1):
	u_l.append([ac_u, i])

for i in range(ac_d+1, R):
	d_l.append([i, 0])
for i in range(1,C):
	d_l.append([R-1, i])
for i in range(R-2, ac_d-1, -1):
	d_l.append([i, C-1])
for i in range(C-2, 0, -1):
	d_l.append([ac_d, i])
print(solution())
