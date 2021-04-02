
def get_result(s, e, w):
	l = e-s+1
	r = 2*w+1
	if l%r == 0:
		return l//r
	else:
		return l//r+1

def solution(n, stations, w):
	answer = 0 
	if stations[0]-w-1>=1:
		answer += get_result(1, stations[0]-w-1, w)
	for i in range(1, len(stations)):
		answer += get_result(stations[i-1]+w+1, stations[i]-w-1, w)
	if stations[len(stations)-1]+w+1 <= n:
		answer += get_result(stations[len(stations)-1]+w+1, n, w)
	return answer


# print(solution(11, [4,11], 1))
print(solution(16, [9], 2))