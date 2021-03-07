def solution(tickets):  
    answer = []
    g = dict()
    cities = []
    # 모든 도시의 행선지 리스트를 부여
    for ticket in tickets:
        g[ticket[0]] = []
        g[ticket[1]] = []
        if ticket[0] not in cities:
            cities.append(ticket[0])
        if ticket[1] not in cities:
            cities.append(ticket[1])
    
    # 각 도시의 행선지를 추가
    ticket_num = 1
    for ticket in tickets:
        g[ticket[0]].append((ticket[1], ticket_num)) # 출발지 , 도착지 주입
        ticket_num += 1
    # 행선지 들을 각각 알파벳 순으로 정렬
    for city in cities:
        g[city].sort()

    # 티켓 사용 횟수
    ticket_use_cnt = 0
    # dfs
    used_ticket = []
    route =[]
    dfs(g, "ICN", route, ticket_use_cnt, len(tickets), used_ticket, answer)
    return answer

def dfs(g, dep, route, ticket_use_cnt, ticket_len, used_ticket, answer):
    '''
    g : graph
    dep : departure
    route : route
    ticket_use_cnt : count of ticket usage
    ticket_len : total number of tickets
    used_ticket : specific used ticket number
    ''' 
    route.append(dep)
    if ticket_use_cnt == ticket_len and len(answer) == 0:
        for city in route:
            answer.append(city)
        return
    for arr_info in g[dep]:
        # arr info : (arr_city, ticket number)
        arr_city = arr_info[0]
        ticket_n = arr_info[1]
        if ticket_n not in used_ticket:
            used_ticket.append(ticket_n) # 티켓 사용
            ticket_use_cnt += 1
            dfs(g, arr_city, route, ticket_use_cnt, ticket_len, used_ticket, answer)
            ticket_use_cnt -= 1
            used_ticket.pop()
    route.pop()
    return





solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]])
solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]])
solution([["ICN", "A"], ["ICN", "B"], ["B", "ICN"]])
# solution([['ICN','B'],['B','ICN'],['ICN','A'],['A','D'],['D','A']])
# solution([["ICN","A"], ["ICN","A"], ["A","ICN"], ["A","C"]])
# solution([["ICN", "A"], ["A", "C"], ["A", 'D'], ["D", "B"], ["B", "A"]])
# solution([["ICN", 'A'],['A','B'],['B','A'],['A',"ICN"],["ICN",'A']])
# solution([["ICN","BOO"], ["ICN", "COO"], [ "COO", "DOO" ], ["DOO", "COO"], [ "BOO", "DOO"] ,["DOO", "BOO"], ["BOO", "ICN" ], ["COO", "BOO"]])
# solution([["ICN", "COO"], ["ICN", "BOO"], ["COO", "ICN"], ["BOO", "DOO"]])