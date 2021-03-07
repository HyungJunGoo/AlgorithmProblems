# Binary Search

def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    left = 1
    right = distance

    while left <= right:
        mid = (left+right)//2
        prev_rock = 0
        remove_cnt = 0

        for next_rock in rocks:
            if next_rock-prev_rock < mid:
                remove_cnt += 1
            else:
                prev_rock = next_rock
        if distance - prev_rock < mid:
            remove_cnt += 1

        if remove_cnt <= n:
            answer = max(answer, mid)
            left = mid + 1
        else:
            right = mid - 1
    return answer

distance = 25
rocks = [2, 14, 11, 21, 17]	
n = 2
result = solution(distance, rocks, n)
print(result)