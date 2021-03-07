#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer;
    int n = participant.size();
    map<string, int> _participant;
    for(int i=0; i<n;i++){
        if(_participant[participant[i]]){
            _participant[participant[i]] += 1;
            cout  << "_participant[" << participant[i] << "] "<< _participant[participant[i]] << endl;
            continue;
        }
        _participant[participant[i]] = 1;
        cout  << "_participant[" << participant[i] << "] "<< _participant[participant[i]] << endl;
    }
    for (int i = 0; i < n-1; i++) // for completion
    {
        _participant[completion[i]] -=1;
    }
    for(auto itr = _participant.begin(); itr != _participant.end(); itr++){
        if(itr->second != 0){
            answer += itr->first;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> participant {"leo", "kiki", "eden", "kiki"};
    vector<string> completion {"eden", "kiki", "leo"};
    string answer;
    answer = solution(participant, completion);
    cout << answer << endl;
    return 0;
}