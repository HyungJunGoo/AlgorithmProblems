import bisect
def solution(info, query):
    answer = []
    
    language = ['java', 'cpp', 'python', '-']
    position = ['backend', 'frontend', '-']
    level = ['junior', 'senior', '-']
    food = ['pizza', 'chicken', '-']

    group = {}
    for l in language:
        for p in position:
            for lev in level:
                for f in food:
                    name = l+p+lev+f
                    group[name]= []
    for candidate in info:
        s = candidate.split(' ')
        candidate_lang = [s[0], '-']
        candidate_posi = [s[1], '-']
        candidate_car = [s[2], '-']
        candidate_food = [s[3], '-']
        for l in candidate_lang:
            for p in candidate_posi:
                for c in candidate_car:
                    for f in candidate_food:
                        key = l+p+c+f
                        group[key].append(int(s[4]))

    for k,v in group.items():
        group[k] = sorted(v)
    
    for q in query:
        count = 0
        q_info, score = q.replace(" and ", '').split(' ')
        score = int(score)
        group_size = len(group[q_info])
        count = group_size-bisect.bisect_left(group[q_info], score, 0, group_size)
        answer.append(count)
    return answer 

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
solution(info, query)