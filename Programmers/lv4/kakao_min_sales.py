import sys

answer = [sys.maxsize]
def min_sales(T, member_info, team_info, leaders, n, selected_member):
    if n == T:
        candidate = [member_info[x] for x in selected_member]
        s = sum(candidate)
        if min(answer) > s:
            answer.append(s)
        return 
    candidate = [member_info[x] for x in selected_member]

    current_sales = sum(candidate)
    if min(answer) <= current_sales:
        return
    for m in team_info[leaders[n]]:
        if m[0] in selected_member:
            min_sales(T, member_info, team_info, leaders, n+1, selected_member)
        else:
            selected_member.append(m[0])
            min_sales(T, member_info, team_info, leaders, n+1, selected_member)
            selected_member.pop()
    return

def solution(sales, links):
    member_info = dict()
    for i, s in enumerate(sales):
        member_info[i+1] = s
    team_info = dict()

    for l in links:
        team_info[l[0]] = [[l[0], member_info[l[0]]]]

    for l in links:
        team_info[l[0]].append([l[1], member_info[l[1]]])
    # team_info = sorted(team_info.items(), key=lambda item: item[0])
    team_num = len(team_info)
    leaders = sorted(list(team_info.keys()))
    min_sales(len(team_info), member_info, team_info, leaders, 0, [])
    print(answer)
    print(min(answer))
    return answer

sales = [14, 17, 15, 18, 19, 14, 13, 16, 28, 17]
links = [[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]

solution(sales, links)