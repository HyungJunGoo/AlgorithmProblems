# 9251 <LCS (Longest Common Subsequence)>
import sys
input = lambda: sys.stdin.readline()

def solution(str1, str2):
    n=len(str1)
    m=len(str2)
    dp = [list(0 for _ in range(m+1)) for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if str1[i-1]==str2[j-1]:
                dp[i][j] = dp[i-1][j-1]+1   
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    print(dp[n][m])
    print(dp)
    return

if __name__ == "__main__":
    str1= input()
    str2= input()
    str1= str1[:-1]
    str2= str2[:-1]
    solution(str1, str2)