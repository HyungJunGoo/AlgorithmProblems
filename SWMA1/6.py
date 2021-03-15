import sys
import heapq as hq
import copy

def main():
    N = int(sys.stdin.readline())
    l = list(map(int, sys.stdin.readline().split()))
    
    # 총 M번 비교하게됨 2^M = N
    M = 0
    _N = copy.copy(N)
    while _N//2 > 0:
        M+=1
        _N = _N//2
    answer = 0
    for i in range(M):
        l_hq = []
        r_hq = []
        l_result = []
        r_result = []
        for idx in range(0, N//2**(i+1)):
            hq.heappush(l_hq, -l[idx])
        for idx in range(N//2**(i+1), N//2**(i)):
            hq.heappush(r_hq, -l[idx])
        for _ in range(N//2**(i+1)):
            l_result.append(-hq.heappop(l_hq))
            r_result.append(-hq.heappop(r_hq))
        if l_result[0] > r_result[0]:
            l = l[N//(2**(i+1)):]
            answer += l_result[0]
        else:
            l = l[N//(2**(i+1)):]
            l = l[0:N//(2**(i+1))]
            answer += r_result[0]
    print(answer)
    return

if __name__=="__main__":
    main()