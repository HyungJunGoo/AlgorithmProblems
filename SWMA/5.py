import sys

def main():
    N = int(sys.stdin.readline())
    d = dict()
    time_d = dict()
    score_list=[]
    for _ in range(N**2):
        info = list(map(int, sys.stdin.readline().split()))
        score = info[0]
        score_list.append(score)
        count = info[1]
        times = info[2:]
        d[score] = times
    for s in score_list:
        for t in d[s]:
            time_d[t] = s
    answer = 0
    for _,v in time_d.items():
        answer += v
    print(answer)

if __name__=="__main__":
    main()