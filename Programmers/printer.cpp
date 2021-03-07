#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int priorities_size = priorities.size();
    queue<pair<int, int>> q;
    int i =0;
    for(auto x : priorities){
        q.push(make_pair(x, i));
        i++;
    }

    int val_location = priorities[location];
    while (!q.empty())
    {
        int front = q.front().first;
        int idx = q.front().second;
        int max = *max_element(priorities.begin(), priorities.end());
        if(front != max){
            q.pop();
            q.push(make_pair(front, idx));
            continue;
        }
        else
        {
            q.pop();
            auto itr = find(priorities.begin(), priorities.end(), front);
            priorities.erase(itr);
            answer ++;
            if( idx == location && front == val_location)
                break;
        }
    }
    
    return answer;
}

int main()
{
    vector<int> priorities1 = {2, 1, 3, 2};
    vector<int> priorities2 = {1, 1, 9, 1, 1, 1};
    
    int location = 2;
    int location2 = 0;
    int result = solution(priorities1, location);
    int result2 = solution(priorities2, location2);
    cout << result << endl;
    cout << result2 << endl;
    return 0;
}