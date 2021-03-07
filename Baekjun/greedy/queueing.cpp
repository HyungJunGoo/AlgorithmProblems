/*
N명의 사람들은 매일 아침 한 줄로 선다. 이 사람들은 자리를 마음대로 서지 못하고 오민식의 지시대로 선다.

어느 날 사람들은 오민식이 사람들이 줄 서는 위치를 기록해 놓는다는 것을 알았다. 

그리고 아침에 자기가 기록해 놓은 것과 사람들이 줄을 선 위치가 맞는지 확인한다.

사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지만을 기억한다. N명의 사람이 있고, 사람들의 키는 1부터 N까지 모두 다르다.

각 사람들이 기억하는 정보가 주어질 때, 줄을 어떻게 서야 하는지 출력하는 프로그램을 작성하시오.
*/

#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
    deque<int> q(int people, map<int,int> left_remember){
        deque<int> result;
        for(int i=people; i>=1; i--){
            if(i == people){
                result.push_back(i);
            }
            else{
                int larger = 0;
                for(int j=0; j<result.size(); j++){
                    if(result[j] > i){
                        larger++;
                        if(larger == left_remember[i]){
                            result.insert(result.begin()+j+1, i);
                            break;
                        }
                    }
                }
                if(larger != left_remember[i])
                    result.push_front(i);
                
            }
        }
        return result;
    }

};

int main()
{
    int people;
    cin >> people;
    map<int, int> left_remember;

    for(int i=1; i<=people; i++){
        int left_people;
        cin >> left_people;
        left_remember[i] = left_people;
    }
    Queue q;
    deque<int> answer = q.q(people, left_remember);
    for(int n : answer)
        cout << n << " ";
    cout << "\n";
    return 0;
}