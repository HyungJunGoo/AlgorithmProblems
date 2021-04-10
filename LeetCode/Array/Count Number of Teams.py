#There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

# You have to form a team of 3 soldiers amongst them under the following rules:

# Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
# A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
# Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


class Solution(object):
	

    def numTeams(self, rating):
        answer = 0
        l = len(rating)
        greater = [0]*l
        less = [0]*l
        for i in range(l-1):
        	for j in range(i+1, l):
        		if rating[i] < rating[j]:
        			greater[i] += 1
        		elif rating[i] > rating[j]:
        			less[i] += 1
        for i in range(l-2):
        	for j in range(i+1, l):
        		if rating[i] < rating[j]:
        			answer += greater[j]
        		elif rating[i] > rating[j]:
        			answer += less[j]
        return answer


if __name__ == "__main__":
	rating = [4,7,9,5,10,8,2,1,6]
	
	solution = Solution()
	if solution.numTeams(rating) == 24:
		print("OK")