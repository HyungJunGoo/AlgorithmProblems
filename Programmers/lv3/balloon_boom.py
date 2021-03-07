import sys
def solution(a):
    answer = 0
    l = len(a);

    left = []
    right = []
    
    m = sys.maxsize

    for i in range(l):
        if a[i] < m:
            m = a[i]
            left.append(m)
        else: left.append(m)
    
    m = sys.maxsize
    for i in range(l):
        if a[l-1 - i] < m:
            m = a[l-1-i]
            right.append(m)
        else: right.append(m)
    right.reverse()
    for i in range(l):
        if i == 0 or i == l-1:
            answer += 1
        else:
            if left[i-1] < a[i] and right[i+1] < a[i]:
                continue
            else:
                answer += 1

    return answer

solution([9,-1,-5])
solution([-16, 27, 65, -2, 58, -92, -71, -68, -61, -33])