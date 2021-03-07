def solution(N, home):
    dp = [[0,0,0] for _ in range(N)]
    for i in range(3):
        dp[0][i] = home[0][i]
    for i in range(1, N):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + home[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + home[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + home[i][2]
    return min(dp[N-1])

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