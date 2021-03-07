
def solution(food_times, k):
    answer = 0
    total_foods = sum(food_times)
    # 더이상 먹을 것 없는 경우
    if total_foods - k <= 0:
        return -1
    num_food = len(food_times)
    
    food_idx = []
    for i, f in enumerate(food_times):
        food_idx.append([f, i+1])
    idx=0 # sorted food 에서 index
    cnt=0 # sorted food 에서  sorted_food[idx] 번 째 음식을 다먹을 때 까지
    sorted_food_times = food_idx.copy()
    sorted_food_times.sort()
    left_food = k # k 개에서 부터 남은 음식 체크
    while cnt < k:
        if idx==0: # 처음 food_times이 가장 작은 음식
            cnt += sorted_food_times[idx][0]*num_food
            left_food -= sorted_food_times[idx][0]*num_food
        else:
            cnt += (sorted_food_times[idx][0] - sorted_food_times[idx-1][0]) * num_food
            left_food -= (sorted_food_times[idx][0] - sorted_food_times[idx-1][0]) * num_food
        same_cnt = 0
        if cnt > k: break
        num_food -= 1  
        idx+=1
    tmp_l = [f for f in food_idx if f[0]>=sorted_food_times[idx][0]] # need to fix
    if left_food == 0:
        answer = tmp_l[left_food][1]
    elif left_food<0:
        left_food += num_food
        answer = tmp_l[left_food][1]
    return answer
solution([4,2,3,6], 10)