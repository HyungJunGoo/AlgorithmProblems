#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i = 1;
    map<char, int> sk;
    for( auto s : skill){
        sk[s] = i++;
    }
    int num = skill_trees.size();
    for(int x=0; x<num; x++){
        int j = 1;
        for(auto c : skill_trees[x]){
            if(!sk[c]) continue;
            else if(sk[c] == j ) j++;
            else if (sk[c] != j) {
                j = 0;
                break;
            }
        }
        if(j >= 1)
            answer++;
    }
    return answer;
}

int main()
{
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << endl;
}