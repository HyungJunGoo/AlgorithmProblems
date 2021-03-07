#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int l = name.length();
    string init_str = "";
    for(int i=0; i<l; i++)
        init_str += 'A';
    int current = 0;
    while(true){
        // check if the word is given name
        cout << init_str << " ";
        if(init_str == name)
            break;
        else{
            int c_n = int(name[current]) - 'A';
            if(c_n <= 13){
                answer += c_n;
            }
            else
                answer += abs(c_n - 26);
        }
        init_str[current] = name[current];

        // find which way(left or right) is faster, then move
        for(int i=1; i<l; i++){
            if(init_str[current + i] != name[current+i]){ // right
                current += i;
                answer += i;
                break;
            }
            else if(init_str[current-i+l] != name[current-i+l]){ // left
                current = current-i+l;
                answer += i;
                break;
            }
        }

    }
    return answer;
}

int main()
{
    cout << solution("JAN") << endl;
}