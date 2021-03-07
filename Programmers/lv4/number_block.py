import time

# i번 위치의 블록에 대해서, i를 (자기자신이 아닌 수 중에서) 나누어 떨어뜨리게 하는 수 중에 가장 큰 수
# i를 나누어 떨어뜨리는 약수중 1이아닌 가장 작은 약수로 나눴을 때의 몫

def solution(begin, end):
    answer = []

    max_number = 10000000
    
    for n in range(begin, end+1):
        if n == 1:
            answer.append(0)
        else:
            start = 2 if n % 2 == 0 else 3
            answer.append(1)
            for i in range(start, int(n**0.5)+1):
                if n % i == 0:
                    x = n//i
                    if x <= max_number:
                        answer[-1] = x
                        break
    return answer

t = time.time()
# print(t)s
# print(solution(5000, 15000))
# solution(1, 10000)
print(solution(999990000, 1000000000))
t_ = time.time()
print(t_ - t)