/*
메모이제이션!!
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

    X가 3으로 나누어 떨어지면, 3으로 나눈다.
    X가 2로 나누어 떨어지면, 2로 나눈다.
    1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

예시
d0   d1   d2   d3   d4 
10 -> 9 -> 3 -> 1 
10 -> 9 -> 3 -> 2 -> 1
10 -> 5 -> 4 -> 2 -> 1

12 -> 6 -> 2 -> 1
12 -> 4 -> 2 -> 1

14 -> 7 -> 6 -> 2 -> 1

16 -> 15 -> 5 -> 4 -> 2 -> 1
16 -> 8  -> 4 -> 2 -> 1
답 3

*/
#include <bits/stdc++.h>
using namespace std;

class make_one{
    int dp[1000001];
public:
    int Solution(int val){
        dp[1] = 0;

        for(int i = 2; i<=val; i++){
            dp[i] = dp[i-1]+1;
            if(i%2==0){
                dp[i] = min(dp[i], dp[i/2]+1);
            }
            if(i%3==0){
                dp[i] = min(dp[i], dp[i/3]+1);
            }
        }
        return dp[val];
    }
};


int main()
{
    
    make_one m;
    cout << m.Solution(2) << endl;
    
    return 0;
}