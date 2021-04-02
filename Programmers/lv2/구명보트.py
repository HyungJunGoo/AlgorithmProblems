def solution(people, limit):
    answer = 0
    people = sorted(people)
    l,r = 0, len(people)-1
    while l <= r:
    	if people[r]+people[l] <= limit:
    		l+=1
    	r-=1
    	answer += 1
    	if l==r:
    		answer+=1
    		break
    return answer

if solution([70, 50, 80, 50], 100) == 3:
	print("OK1") 
if solution([70, 80, 50], 100) == 3:
	print("OK2")
if solution([10, 20, 30, 40, 50, 60], 70) == 3:
	print("OK3") 