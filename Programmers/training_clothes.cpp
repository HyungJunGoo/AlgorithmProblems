#include<string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    int lost_n = lost.size();
    int reserve_n = reserve.size(); 
    int answer = n - lost_n;    
    vector<int> _reserve (n+2, 0);
    for (int i = 0; i < reserve_n; i++){
        _reserve[reserve[i]] = reserve[i];

    }
    for (int i = 0; i < lost_n; i++){
        if(_reserve[lost[i]] != 0){
            _reserve[lost[i]] = 0;
            lost[i] = 0;
            answer++;
        }
    }
    for (int i = 0; i < lost_n; i++)
    {
        if(lost[i] == 0) continue;
        if(_reserve[lost[i] - 1] != 0  ){
            answer++;
            _reserve[lost[i] - 1] = 0;
        }
        else if(_reserve[lost[i] + 1] != 0 ){
            answer++;
            _reserve[lost[i] + 1] = 0;
        }
    }
    return answer;
}

int main()
{
    int n1 = 8;
    vector<int> lost_1 = {4,5};
    vector<int> reserve_1 = {5,6};
    int answer = solution(n1, lost_1, reserve_1);

    cout << answer << endl;

    int n2 = 5;
    vector<int> lost_2 = {2,4};
    vector<int> reserve_2 = {1,3,5};
    answer = solution(n2, lost_2, reserve_2);

    cout << answer << endl;

    int n3 = 3;
    vector<int> lost_3 = {3};
    vector<int> reserve_3 = {1};
    answer = solution(n3, lost_3, reserve_3);

    cout << answer << endl;

    return 0;
}