
def check(u_i, b_i):
    if len(u_i) != len(b_i):
        return False
    for i in range(0, len(u_i)):
        if b_i[i] == '*':
            continue
        if u_i[i] != b_i[i]:
            return False
    return True
    

origin_id_num = dict()

def dfs(idx, user_id, banned_id ,current_set, answer_set):
    # 마지막 banned id
    if idx == len(banned_id):
        # logic
        current_set_list = [origin_id_num[u_i] for u_i in current_set]
        current_set_list.sort()
        num_str = ""
        for u_i in current_set_list:
            num_str += str(u_i)
        answer_set.add(num_str)
        return
    
    # banned_id의 후보 찾기
    l = [u_i for u_i in user_id if check(u_i, banned_id[idx])]
    
    # set에 l에 있는 id를 하나씩 순서대로 넣을 수 있으면 dfs
    for l_i in l:
        if l_i not in current_set:
            current_set.add(l_i)
            dfs(idx+1, user_id, banned_id, current_set, answer_set)
            current_set.remove(l_i)
    return


def solution(user_id, banned_id):
    answer = 0
    
    banned_l = len(banned_id)

    # origin_id_num = dict()
    for i, v in enumerate(user_id):
        origin_id_num[v] = i
    current_set = set()
    answer_set = set()
    dfs(0, user_id, banned_id, current_set, answer_set)
    answer = len(answer_set)


    return answer