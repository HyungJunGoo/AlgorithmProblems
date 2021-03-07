import bisect

def solution(A, B):
    answer = 0

    A = sorted(A)
    B = sorted(B)

    l = len(B)

    for a in A:
        try:
            i = bisect.bisect_right(B, a)
            print(f"a : {a} , b: {i} of B ;{B[i]} and B is {B} which l is {l}")
            if i < l:
                print("answer!")
                answer+=1
                l -= 1
                del B[i]
            else: break
        except IndexError as e:
            pass
    return answer

A = [5,1,3,7]
B = [2,2,6,8]
print(solution(A,B))