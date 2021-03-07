#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int l = name.length();
    
    int cursor = 0;
    int C_num = int(name[0]) - 'A';

    // Right
    int r_val = 0;
    string init_str = "";
    for(int i=0; i<l; i++)
        init_str += 'A';

    for(int i = 0; i<l; i++){
        int c_n = int(name[i]) - 'A';
        if(c_n == 0){ // name[i] == 'A'
            // nothing to do
        }
        else{
            if(c_n <= 13){ // we move to right
                r_val += c_n;
            }
            else { // we move to left
                r_val  += abs(c_n - 26);
            }
            init_str[i] = name[i];
        }
        if(init_str == name)
            break;
        r_val++;
    }
    
    // Left
    int l_val = 0;
    init_str = "";
    for(int i=0; i<l; i++)
        init_str += 'A';

    for(int i = l-1; i>=0; i--){
        int c_n;
        if(i == l-1)
            c_n = int(name[0])  - 'A';
        else
            c_n = int(name[i+1]) - 'A';
        if(c_n == 0){ // name[i] == 'A'
            // nothing to do
        }
        else{
            if(c_n <= 13){ // we move to right
                l_val += c_n;
            }
            else { // we move to left
                l_val  += abs(c_n - 26);
            }
            if (i == l-1)
                init_str[0] = name[0];
            else
                init_str[i+1] = name[i+1];
        }
        // cout << "str : " << init_str << endl;
        if(init_str == name)
            break;
        l_val++;
    }
    // cout << r_val << ", " << l_val << endl;
    answer = min(r_val, l_val);
    return answer;
}