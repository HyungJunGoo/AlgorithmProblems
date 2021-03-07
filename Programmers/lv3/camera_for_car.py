import heapq

def solution(routes):
    rev_routes = []
    for route in routes:
        rev_routes.append([route[1], route[0]])
    heapq.heapify(rev_routes)
    answer = 0
    while len(rev_routes) > 0:
        out = heapq.heappop(rev_routes)[0]
        print(out)
        while len(rev_routes)>0 and rev_routes[0][1] <= out:
            heapq.heappop(rev_routes)
        answer += 1
    return answer

if __name__ == "__main__":
    routes = [[-20,15], [-14,-5], [-18,-13], [-5,-3]]
    answer = solution(routes)
    print(answer)