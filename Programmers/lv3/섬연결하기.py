def get_parent(d,n):
	if d[n] == n:
		return n
	return get_parent(d, d[n])
def solution(n, costs):
    answer = 0
    costs=sorted(costs, key=lambda x:x[2])
    d = {i : i for i in range(n)} # 부모 가리킴
    s = set()
    for cost in costs:
    	a,b,c = cost
    	if get_parent(d, a) != get_parent(d, b):
    		answer += c
    		p_a = get_parent(d,a)
    		p_b = get_parent(d,b)
    		if p_a > p_b:
    			d[p_a] = p_b
    		elif p_b > p_a:
    			d[p_b] = p_a
    		s.add(a)
    		s.add(b)
    	check=True
    	p = -1
    	for i in range(n):
    		if p == -1:
    			p = get_parent(d, i)
    			continue
    		if p != get_parent(d, i):
    			check = False
    			break
    	if check: break
    return answer

if solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]])==4:
	print("OK1")
if solution(5, [[0, 1, 1], [3, 1, 1], [0, 2, 2], [0, 3, 2], [0, 4, 100]]) == 104:
	print("OK2")
if solution(4,[[0, 1, 5], [1, 2, 3], [2, 3, 3], [3, 1, 2], [3, 0, 4]]) == 9:
	print("OK3")
if solution(7, [[0,6,12],[0,3,28],[0,1,67],[0,4,17], [1,3,24],[1,4,62],[2,4,20],[2,5,37],[3,6,13],[4,5,45],[4,6,73]]) == 123:
	print("OK4")
if solution(4,[[0,1,1],[0,2,2],[2,3,1]]) == 4:
	print("OK5")