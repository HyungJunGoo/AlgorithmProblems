def solution(n, words):
    answer = []
    w_set = set()
    for i in range(len(words)):
    	if i == 0:
    		if len(words[i]) == 1:
    			answer.append(1)
    			answer.append(1)
    			break
    		w_set.add(words[i])
    	else:
    		if words[i][0] != words[i-1][len(words[i-1])-1] or words[i] in w_set:
    			if (i+1)%n == 0:
    				answer.append(n)
    				answer.append((i+1)//n)
    			else:
    				answer.append((i+1)%n)
    				answer.append((i+1)//n + 1)
    			break
    		w_set.add(words[i])

    if len(answer) == 0:
    	answer.append(0)
    	answer.append(0)
    return answer

if solution(3,["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]) == [3,3]:
	print("1 right")
if solution(5, ["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]) == [0,0]:
	print("2 right")
if solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]) == [1,3]:
	print("3 right")