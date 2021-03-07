/*
두 정수 N과 F가 주어진다. 지민이는 정수 N의 가장 뒤 두 자리를 적절히 바꿔서 N을 F로 나누어 떨어지게 만들려고 한다. 만약 가능한 것이 여러 가지이면, 뒤 두 자리를 가능하면 작게 만들려고 한다.

예를 들어, N=275이고, F=5이면, 답은 00이다. 200이 5로 나누어 떨어지기 때문이다. N=1021이고, F=11이면, 정답은 01인데, 1001이 11로 나누어 떨어지기 때문이다.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, F;
    cin >> N >> F;
    string _N = to_string(N);
    int len = _N.length();
    _N.replace(_N.end()-2, _N.end(), "00");
    N = stoi(_N);
    while (N % F != 0)
        N++;
    cout << to_string(N).substr(to_string(N).length()-2, 2) << endl;
    return 0;
}
