#include <bits/stdc++.h>

using namespace std;

string util(string str){
    int l = str.length();
    string result = "";
    for (int i = 0; i <l ; i++)
    {
        if((int(str[i]) >= int('a') && int(str[i]) <= int('z')) || (int(str[i]) >= int('A') && int(str[i]) <= int('Z')))
            result += tolower(str[i]);
        else
            result += str[i];
    }
    return result;
}

bool check_valid(char c){
    
    if((int(c) >= int('a') && int(c) <= int('z')) || (int(c) >= int('A') && int(c) <= int('Z')))
        return true;
    

    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> um_1;
    unordered_map<string, int> um_2;

    str1 = util(str1);
    
    str2 = util(str2);
    
    for(int i=0; i<str1.length()-1; i++){
        string tmp = "";
        if(check_valid(str1[i+1]) && check_valid(str1[i]))
            tmp += str1.substr(i,2);
        else
            continue;
        if(um_1[tmp])
            um_1[tmp] += 1;
        else
            um_1[tmp] = 1;
    }
        
    for(int i=0; i<str2.length()-1; i++){
        string tmp = "";
        if(check_valid(str2[i+1]) && check_valid(str2[i]))
            tmp += str2.substr(i,2);
        else
            continue;
        if(um_2[tmp])
            um_2[tmp] += 1;
        else
            um_2[tmp] = 1;
    }
    
    int sum = 0;
    int com = 0;
    
    for (auto p : um_1){
        if(um_2[p.first]){
            sum += max(um_2[p.first], p.second);
        }
        else{
            sum += p.second;
        }
    }
    for (auto p : um_2){
        if(!um_1[p.first])
            sum += p.second;
    }
    
    // get com
    for (auto p : um_1){
        if(um_2[p.first])
            com += min(um_2[p.first], p.second);
    }
    
    
    if (com == 0 && sum == 0)
        answer = 65536;
    else{
        double j = double(com)/double(sum);
        answer += int(j*65536);    
    }
    

    return answer;
}