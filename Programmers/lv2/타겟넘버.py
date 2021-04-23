# 타겟넘버

answer = 0
gtarget = 0
def dfs(numbers, i, v):
    global answer
    if len(numbers) == i:
        if v == gtarget:
            answer += 1
        return
    dfs(numbers, i+1, v+numbers[i])
    dfs(numbers, i+1, v-numbers[i])
def solution(numbers, target):
    global answer, gtarget
    gtarget = target
    dfs(numbers, 0, 0)
    
    return answer