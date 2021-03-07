#include <bits/stdc++.h>
using namespace std;

class Log{
public:
    int min_gap(deque<int> logs, int num)    {
        sort(logs.begin(), logs.end());
        deque<int> result;
        result.clear();
        result.push_back(logs.back());
        logs.pop_back();
        bool turn = true;
        for(int i = num-2; i>=0; i--){
            if(turn){
                result.push_front(logs[i]);
            }
            else{
                result.push_back(logs[i]);
            }
            turn = !turn;
        }
        int diff = 0;
        for(int i=0; i<num-1; i++){
            if(diff < abs(result[i] - result[i+1]))
                diff = abs(result[i] - result[i+1]);
        }

        return diff;

    }
};

int main()
{
    int Test_cases;
    cin >> Test_cases;
    vector<int> result;
    for(int i=0; i<Test_cases; i++){
        Log log;
        deque<int> logs;
        int nums;
        cin >> nums;
        for(int j=0; j<nums; j++){
            int tmp;
            cin >> tmp;
            logs.push_back(tmp);
        }
        result.push_back(log.min_gap(logs, nums));
    }

    for(int n : result)
        cout << n << endl;
    return 0;
}