/*
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
*/

#include <bits/stdc++.h>
using namespace std;

class LostBrackets{
public:
    int util(string s){
        deque<int> numbers;
        deque<bool> operations;
        int n = s.length();
        string tmp = "";
        for(int i=0; i<n; i++){
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
                tmp += s[i];
            }
            else{
                numbers.push_back(stoi(tmp));
                tmp = "";
                if(s[i] == '+'){
                    operations.push_back(true);
                }
                else
                    operations.push_back(false);
            }
        }
        numbers.push_back(stoi(tmp));
        int result = numbers[0];
        numbers.pop_front();
        int num_n = numbers.size();
        bool cur_minus = false;
        for(int i=0; i<num_n; i++){
            if(operations[i] == false){ // if the operation is minus
                cur_minus = true;
            }
            if(cur_minus == false){
                result += numbers[i];
            }
            else{
                result -= numbers[i];
            }
        }
        return result;

    }
};

int main()
{
    string s ;
    cin >> s;
    LostBrackets lostbrackets;
    cout << lostbrackets.util(s) << endl;

    return 0;
}