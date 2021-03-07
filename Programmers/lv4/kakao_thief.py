
def solution(money):
    # i 번 째 집에서 도둑질 할 수 있는 최대 금액: dp[i]
    # dp[i] = max(dp[i-1], dp[i-2] + money[i])

    # case 1: 첫번 째 집을 터는 경우 ( 맨 마지막 집을 고려할 수 없음)
    dp1 = [0] * len(money)
    dp1[0] = money[0]
    dp1[1] = max(money[1], money[0])
    
    for i in range(2, len(money)-1):
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])
    
    # case 2: 첫번 째 집을 털지 않는 경우 ( 맨 마지막 집을 고려함)
    dp2 = [0] * len(money)
    dp2[0] = 0
    dp2[1] = money[1]
    for i in range(2, len(money)):
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])

    return max(max(dp1), max(dp2))

money = [1,2,3,1]
solution(money)