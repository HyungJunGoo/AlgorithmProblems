import sys
def main():
    skill_list = sys.stdin.readline().split()
    d = dict()
    non_pre = []
    for s in skill_list:
        d[s] = []
        non_pre.append(s)
    N = int(sys.stdin.readline())
    for _ in range(N):
        x, y = sys.stdin.readline().split()
        d[x].append(y)
        if y in non_pre:
            non_pre.remove(y)

    for begin in non_pre:
        route = begin
        dfs(begin, d, route)
    return

def dfs(begin, d, route):
    if len(d[begin]) == 0:
        print(*route)
    for n in d[begin]:
        dfs(n, d, route+n)
    return

if __name__=="__main__":
    main()