#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    map<string, pair<int,int> > q_map; // query map
    int words_l = words.size();
    int queries_l = queries.size();
    vector<int> answer (queries_l, 0);

    for(int i=0; i<queries_l; i++){
        pair<int, int> q_pair;
        int idx = 0;
        int l = 0;
        int q_l = queries[i].length();
        if(queries[i][0] == '?'){ //접두사 부터 ? 인 경우
            for(int j=q_l-1; j>0; j--){
                if(queries[i][j] == '?'){
                    idx = j+1;
                    l = q_l-1-j;
                    break;
                }
            }
        }
        else{
            for(int j=0; j<q_l; j++){
                if(queries[i][j] == '?'){
                    l = j;
                    break;
                }
            }
        }
        q_pair = make_pair(idx, l);

        for(int j=0; j<words_l; j++){
            if(words[j].length() == queries[i].length()){
                if( q_pair.first == queries[i].length()){
                    answer[i] ++;
                    continue;
                }
                if(words[j].substr(q_pair.first, q_pair.second) == queries[i].substr(q_pair.first, q_pair.second)){
                    answer[i] ++;
                }
            }
            else
                continue;
        }
        // cout << queries[i] << " : " << q_pair.first << "," << q_pair.second << endl;
    }

    return answer;
}

