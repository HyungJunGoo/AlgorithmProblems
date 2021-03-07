/*
트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 
트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딥니다.
트럭이 다리에 완전히 오르지 않은 경우, 이 트럭의 무게는 고려하지 않습니다.

예를 들어, 길이가 2이고 10kg 무게를 견디는 다리가 있습니다. 
무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.    

*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, cur_w = 0, complete = 0, num = truck_weights.size();
    queue<pair<int, int> > wait;
    deque<pair<int, int> > on_bridge;
    for(auto i : truck_weights)
        wait.push(make_pair(i, 0));
    while(complete < num){
        answer++;
        cout << "time : " << answer << endl;
        if(!on_bridge.empty()){
            for(auto it=on_bridge.begin(); it != on_bridge.end(); it++){
                (*it).second ++;
                cout << (*it).first << " : " << (*it).second << endl;
            }
        }
        if( !on_bridge.empty() && on_bridge.front().second == bridge_length + 1){
            cout << "Found at the end of the bridge !! " << endl;
            cur_w -= on_bridge.front().first;
            on_bridge.pop_front();
            complete++;
        }
        if(!wait.empty() && cur_w<= weight && (cur_w + wait.front().first) <= weight){
            cur_w += wait.front().first;
            pair<int, int> next = wait.front();
            next.second ++;
            on_bridge.push_back(next);
            wait.pop();
        }
    }

    return answer;
}

int main()
{
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};
    // cout << solution(bridge_length, weight, truck_weights) << endl;
    // cout << solution(2,10,{7,4,5,6})<<endl;
    cout << solution(100,100,{10})<<endl;
    return 0;
}