#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    bool laser = false;
    int open = 0, close = 0;
    int len = arrangement.length();
    for(int i=0; i <len; i++){
        if(arrangement[i] == '('){
            if(arrangement[i+1] == ')'){
                laser = true;
                answer+=open;
                i++;
            }
            else{
                open++;
            }
        }
        else if (arrangement[i] == ')'){
            answer+=1;
            open--;
        }
    }
    return answer;
}

int main()
{
    cout << solution("()(((()())(())()))(())") << endl;
    return 0;
}