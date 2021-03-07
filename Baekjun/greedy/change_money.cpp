/*
타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 개수가 가장 적게 잔돈을 준다. 

타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때, 받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.

예를 들어 입력된 예1의 경우에는 아래 그림에서 처럼 4개를 출력해야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

class Change{
public:
    int change(int num){
        int to_change = 1000 - num;
        int cnt = 0;
        while (to_change > 0)
        {
            if(to_change >= 500){
                to_change -= 500;
                cnt++;
                continue;
            }
            else if(to_change >=100){
                cnt += (to_change/100);
                to_change %=100;
                continue;
            }
            else if(to_change >=50){
                cnt += (to_change/50);
                to_change %= 50;
                continue;
            }
            else if(to_change >=10){
                cnt += (to_change/10);
                to_change %=10;
                continue;
            }
            else if(to_change >= 5){
                cnt += (to_change/5);
                to_change %=5;
                continue;
            }
            else if(to_change >= 1){
                cnt += (to_change/1);
                to_change =0;
                continue;
            }
            
        }
        return cnt;
    }
    
};

int main()
{
    Change c;
    int money;
    cin >> money;
    int ans = c.change(money);
    cout << ans << endl;
    return 0;
}