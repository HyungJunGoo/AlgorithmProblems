def solution(N, home):
    result = []
    for i in range(3):
        result.append(dfs(home, 1, home[0][i], i))

    return min(result)

def dfs(home, index, cost, former_colour):
    if index == len(home):
        return cost
    m = 1001
    next_colour = 0
    for i in range(3):
        if i == former_colour: continue
        else:
            if m > home[index][i]:
                m = home[index][i]
                next_colour = i
    return dfs(home, index+1, cost+m, next_colour)

def main():
    N = int(input())
    home = []
    for i in range(N):
        l = input().split()
        n_l = [int(x) for x in l]
        home.append(n_l)

    answer = solution(N, home)
    print(answer)
    return 

if __name__ == "__main__":
    main()