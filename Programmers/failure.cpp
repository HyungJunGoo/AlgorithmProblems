#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool mysort(pair<double, int> &a, pair<double, int> &b){
    
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size(); //people
    vector<int > fail_r(N,0); // stay at
    vector<int> chal(N, num);
    vector<pair<double, int> > result(N);
    for(auto s : stages){
        if (s >N)
            continue;
        else
            fail_r[s-1]++;
    }
    int drop = 0;
    for(int i = 0; i<N ; i++){
        chal[i] -= drop;
        drop += fail_r[i];
    }
    for(int i =0 ; i < N ; i++){
        double rate;
        if(chal[i] != 0)
            rate = (double)fail_r[i]/chal[i];
        else
            rate = 0;
        result[i].second = i+1;
        result[i].first = rate;
    }
    sort(result.begin(), result.end(), mysort);
    for(int i =0 ; i < N ; i++)
        answer.push_back(result[i].second);
    
    return answer;
}   

int main()
{
    vector<int> answer = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    vector<int> answer2 = solution(4, {4, 4, 4, 4});
    return 0;
}