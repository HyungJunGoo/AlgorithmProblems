import sys
import bisect

def main():
    N, M, E = map(int, sys.stdin.readline().split())
    nuts = list(map(int,sys.stdin.readline().split()))
    nuts = sorted(nuts)
    l = [E]
    answer = 0
    while len(l) < M:
        smallest_n = sys.maxsize
        red_line = sys.maxsize
        for n in l:
            find_n = bin_search(n, nuts)
            smallest_n = min(smallest_n, find_n)
            red_line = min(abs(smallest_n-n), red_line)
        l.append(smallest_n)
        answer += red_line
    print(answer)

def bin_search(n, nuts):
    idx_l_n = bisect.bisect_left(nuts, n)
    idx_r_n = bisect.bisect_right(nuts, n)
    return_n = nuts[idx_l_n] if n - nuts[idx_l_n] <= nuts[idx_r_n] - n else nuts[idx_r_n]
    nuts.remove(return_n)
    return return_n

if __name__=="__main__":
    main()