/*
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.
문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.
*/
#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    int cnt = 0;
    for(auto c : number){
        if(st.empty()){
            st.push(c);
            continue;
        }
        while (!st.empty() && c > st.top() && cnt < k)
        {
            st.pop();
            cnt++;
        }
        st.push(c);
    }
    if(cnt < k){
        while(cnt < k){
            st.pop();
            cnt++;
        }
    }
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
    cout << solution("1111", 2) << endl;
    return 0;
}