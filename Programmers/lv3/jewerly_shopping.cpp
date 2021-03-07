#include <bits/stdc++.h>

using namespace std;

bool candidate_check(map<int, int>& current_gem, int kind){

    if (current_gem.size() == kind)
        return true;
    return false;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> gems_map;
    int i = 1;
    for (string gem : gems){
        if(!gems_map[gem])
            gems_map[gem] = i++;
    }
    int kind = i-1;
    int start=0, end=0;
    int len = gems.size();
    map<int, int> current_gem;
    // for(int i=1; i<=kind; i++)
    //     current_gem[i] = 0;
    
    vector<vector<int> > candidate_vect;

    

    while (end <= len && start <= end)
    {
        if(end == 0){
            end += 1;
            if(!current_gem[gems_map[gems[end-1]]])
                current_gem[gems_map[gems[end-1]]] = 1;
            else
                current_gem[gems_map[gems[end-1]]] += 1;
            continue;
        }
        if(candidate_check(current_gem, kind) == true){ // start move
            candidate_vect.push_back({start, end});
            if(start > 0){
                current_gem[gems_map[gems[start-1]]] -= 1;
                if (current_gem[gems_map[gems[start-1]]] == 0){
                    auto it =  current_gem.find(gems_map[gems[start-1]]);
                    current_gem.erase(it);
                }
            }
            start += 1;
        }
        else{ // end move
            if (end < len){
                end += 1;
                if(!current_gem[gems_map[gems[end-1]]])
                    current_gem[gems_map[gems[end-1]]] = 1;
                else
                    current_gem[gems_map[gems[end-1]]] += 1;
            }
            else if (end == len)
                break;
        }
    }
    int min_len = 100000;
    for(auto vect : candidate_vect){
        
        if(vect[1] - vect[0] < min_len){
            min_len = vect[1] - vect[0];
            answer = {vect[0], vect[1]};
        }
    }   
    cout << answer[0] << ", " << answer[1] << endl;
    return answer;
}

int main()
{
    solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    solution({"AA", "AB", "AC", "AA", "AC"});
    solution({"XYZ", "XYZ", "XYZ"});
    solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});

    return 0;
}