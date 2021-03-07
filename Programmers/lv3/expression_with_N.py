# https://programmers.co.kr/learn/courses/30/lessons/42895
def solution(N, number):
    available_numbers = dict()
    for i in range(1,9):
        if i == 1:
            available_numbers[i] = [N]
        else:
            s = int(str(N) * i)
            available_numbers[i] = [s]
            for j in range(1,i):
                a_list = available_numbers[j]
                b_list = available_numbers[i-j]
                available_numbers[i] += operation(a_list, b_list)
        if number in available_numbers[i]:
            return i  
    return -1

def operation(a_list, b_list):
    result = []
    for a in a_list:
        for b in b_list:
            result.append(a+b)
            if a-b > 0:
                result.append(a-b)
            result.append(a*b)
            if b != 0:
                result.append(int(a/b))
    return result

N = 2
number = 11
print(solution(N, number))