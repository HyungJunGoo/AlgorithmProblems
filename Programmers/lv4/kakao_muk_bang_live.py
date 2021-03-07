def solution(food_times, k):
    answer = 0
    total_foods = sum(food_times)
    # 더이상 먹을 것 없는 경우
    if total_foods - k <= 0:
        return -1
    num_food = len(food_times)
    # n 번째 바퀴를 돌 때 체크 관심 n을 찾아야 => N
    # first n ; num_food * n >= k
    N = 1
    while True:
        if N * num_food > k:
            break
        N += 1
    
    empty_food_cnt = 0
    last_food_idx = 0
    for n in range(1, N+1):
        for food_t in  food_times:
            if food_t < n:
                empty_food_cnt += 1
    for i in range(1,num_food+1):
        if food_times[i-1] < N:
            continue
        if i+(N-1)*num_food-empty_food_cnt == k:
            last_food_idx = i-1
            break
    # print(last_food_idx)
    found = False
    print(f"N:{N}")
    while True:
        for idx in range(last_food_idx+1, num_food):
            if food_times[idx] >= N:
                answer = idx
                found = True
                break
        N+=1
        last_food_idx = -1
        if found == True:
            break
    
    

    print(answer+1)
    return answer+1

solution([3,1,2],5)
solution([4,2,3,6],10)
solution([4,2,3,6,7,1,5,8],16)