def dfs(team_info, member_info, dp, team_leaders, node):
    if team_leaders[node] != True:
        return
    for k in team_info[node]:
        dfs(team_info, member_info, dp, team_leaders, k[0])
    sum_child = sum(
        [
            min(
                #k[0]  자식 노드 번호
                #k[1]  자식 노드의 매출
                dp[k[0]][0], dp[k[0]][1]
            )
            for k in team_info[node]
        ]
    ) 
    dp[node][1] = sum_child + member_info[node]
    cnt = 0
    for k in team_info[node]:
        if dp[k[0]][0] > dp[k[0]][1]: 
            cnt += 1
            break
    if cnt > 0: # 자식중에 참석 안하는 경우보다 하는 경우가 더 최적인 경우가 있으면
        dp[node][0] = sum_child
    else:
        dp[node][0] = sum_child + min(
            [
                dp[k[0]][1] - dp[k[0]][0]
                for k in team_info[node]
            ]
        )     
    return min(dp[node][0], dp[node][1])

def solution(sales, links):
    member_info = dict()
    leader_dict = dict()
    for i, s in enumerate(sales):
        member_info[i+1] = s
        leader_dict[i+1] = False
    team_info = dict()
    for l in links:
        team_info[l[0]] = []
        leader_dict[l[0]] = True
    for l in links:
        team_info[l[0]].append([l[1], member_info[l[1]]]) # 코드 리팩터 필요
    team_leaders = list(team_info.keys())

    dp = [[0, member_info[i+1]] for i in range(len(sales))]
    dp.insert(0, [0,0])
    dfs(team_info, member_info, dp, leader_dict, 1)
    return min(dp[1][0], dp[1][1])

sales = [14, 17, 15, 18, 19, 14, 13, 16, 28, 17]
links = [[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]

solution(sales, links)