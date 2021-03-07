/*
함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.
n은 1이상 8000000000 이하인 자연수입니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string num = to_string(n);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    // string _num = "";
    // int len_num = num.length();
    // for(int i=len_num-1; i>=0; i--){
    //     _num += num[i];
    // }
    // cout <<_num << endl;
    answer = stoll(num);
    return answer;
}

int main()
{
    long long test = 1354687998;
    cout << solution(test) << endl;
    return 0;
}