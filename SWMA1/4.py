import sys

def main():
    N = int(sys.stdin.readline())
    l = list(map(int, sys.stdin.readline().split()))

    # 시작 위치 1, 2, 3 중 최대
    cnt = 0
    for i in range(3):
        cnt = max(cnt, util(i, l))
    print(cnt)
    
def util(i, l):
    visited = [i]
    count = 1
    while True:
        count += 1
        if i + l[i] in visited: break
        visited.append(i + l[i])
        i = i + l[i]
    return count
if __name__=="__main__":
    main()