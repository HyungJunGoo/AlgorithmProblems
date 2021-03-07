# 1931

import sys
import heapq as hq

def main():
    N = int(sys.stdin.readline())
    meeting_info = []
    for _ in range(N):
        start, end = map(int, sys.stdin.readline().split())
        meeting_info.append([end, start])
    hq.heapify(meeting_info)
    answer = 0
    while len(meeting_info) > 0 :
        end_time = meeting_info[0][0]
        answer += 1
        hq.heappop(meeting_info)
        while len(meeting_info)>0 and meeting_info[0][1] < end_time:
            hq.heappop(meeting_info)
    
    print(answer)
    return

if __name__ == "__main__":
    main()