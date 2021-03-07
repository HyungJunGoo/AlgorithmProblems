import itertools as it

def solution(orders, course):
    answer = []
    menu_combinations = dict()
    for num_of_course in course:
        menu_combinations[num_of_course] = dict()
        for order in orders:
            order = sorted(order)
            l = it.combinations(order, num_of_course)
            for _l in l:
                combination = ""
                for k in _l:
                    combination += k
                if combination not in menu_combinations[num_of_course]:
                    menu_combinations[num_of_course][combination] = 1
                else: menu_combinations[num_of_course][combination] += 1
        menu_combinations[num_of_course] = {key: val for key, val in sorted(menu_combinations[num_of_course].items(), key = lambda item: item[1], reverse=True)}
        m = 2
        for combi_menu, cnt in menu_combinations[num_of_course].items():
            if cnt >= m: 
                m = cnt
                answer.append(combi_menu)
            else:
                break
    return sorted(answer)
orders = ["XYZ", "XWY", "WXA"]
course = [2,3,4]
solution(orders, course)