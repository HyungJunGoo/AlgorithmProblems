#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    string big_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string small_case = "abcdefghijklmnopqrstuvwxyz";
    int s_len = s.length();
    for (int i = 0; i < s_len; i++)
    {
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        for(int j=0;j<26;j++){
            if(big_case[j] == s[i]){
                if(j + n > 25){
                    answer += big_case[j+n - 25];
                }
                else answer += big_case[j+n];
                // if(j == 25)
                //     answer += big_case[-1+n];    
                // else answer += big_case[j+n];
                break;
            }
            else if(small_case[j] == s[i]){
                if(j + n > 25){
                    answer += small_case[j+n - 24];
                }
                else answer += small_case[j+n];
                
                // if(j == 25)
                //     answer += small_case[-1+n];    
                // else answer += small_case[j+n];
                break;
            }
        }
    }
    return answer;
}
int main()
{
    string s = "i a w W x k k ";
    int n = 3;
    string answer = solution(s, n);
    cout << answer << endl;
}