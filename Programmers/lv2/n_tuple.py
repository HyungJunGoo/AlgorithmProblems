def solution(s):
    answer = []
    s = s[1:-1]
    s += ','
    l = s.split('},')
    l.pop()
    for i in range(len(l)):
        l[i] = l[i][1:]
    tuple_l = dict()
    n_l=list()
    for i in l:
        tmp = i.split(',')
        int_tmp = [int(num) for num in tmp]
        n_l.append(int_tmp)
    for i in n_l:
        tuple_l[len(i)] = i
    tuple_l = {key: value for key, value in sorted(tuple_l.items(), key=lambda item: item[0])}
    for t_l in tuple_l:
        next_add = [n for n in tuple_l[t_l] if n not in answer]
        answer.append(next_add[0])
    return answer

solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")
solution("{{4,2,3},{3},{2,3,4,1},{2,3}}")
solution("{{123}}")
solution("{{20,111},{111}}")
solution("{{1,2,3},{2,1},{1,2,4,3},{2}}")