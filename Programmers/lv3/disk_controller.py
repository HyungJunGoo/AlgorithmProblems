import heapq as hq

def solution(jobs):
    answer = 0
    n = len(jobs)
    i = 0
    l = []
    now = 0 # 현재 시간
    while i < n: 
    	for j in jobs:
    		if now >= j[0] :
    			hq.heappush(l, [j[1], j[0]])
    	if len(l) > 0:
    		sj = hq.heappop(l)
    		now += sj[0]
    		answer += (now - sj[1])
    		i += 1
    		jobs.remove([sj[1], sj[0]])
    		l = []
    	else:
    		now += 1
    return answer//n