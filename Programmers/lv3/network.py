def dfs(adj_list, v, visited):
    visited.append(v)
    for linked_v in adj_list[v]:
        if linked_v not in visited:
            dfs(adj_list, linked_v, visited)
    return 

def solution(n, computers):
    answer = 0

    adj_list = list()
    # adj_list 생성
    for i, computer in enumerate(computers):
        adj_list.append([j for j in range(len(computer)) if j != i and computer[j] == 1])
    # dfs
    visited = list()
    for i in range(n):

        if i not in visited:
            visited.append(i)
        else: continue
        for v in adj_list[i]:
    
            if v not in visited:
                dfs(adj_list, v, visited)
        answer += 1

    print(answer)
    return answer

solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]])
solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]])
