def solution(brown, yellow):
    answer = []
    if yellow >= 3:
        for i in range(1, int(yellow/2)+1):
            y_h = i
            y_w = int(yellow/y_h)
            
            if yellow%y_h != 0:
                continue
            if 2*y_h + (y_w+2)*2 == brown:
                answer.append(y_w+2)
                answer.append(i+2)
                break
    else:
        if yellow == 1 and brown == 8:
            answer.append(3)
            answer.append(3)
        elif yellow == 2 and brown == 10:
            answer.append(4)
            answer.append(3)
    print(answer)
    return answer

solution(12, 4)