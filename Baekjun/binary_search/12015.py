# 12015 <가장 길게 증가하는 수열 2>


from bisect import bisect_left
import sys

input = lambda: sys.stdin.readline()

def solution(N, l):
	ll = []

	a = len(l)
	for i in range(a):
		if i == 0:
			ll.append(l[i])
		else:
			if ll[len(ll)-1] < l[i]:
				ll.append(l[i])
			else:
				idx = bisect_left(ll, l[i])
				ll.insert(idx, l[i])
				del ll[idx+1]
	return len(ll)

if __name__== "__main__":
	N = int(input())
	l = list(map(int, input().split()))
	print(solution(N, l))