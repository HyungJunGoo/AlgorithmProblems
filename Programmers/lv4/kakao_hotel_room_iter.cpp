#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    int size = room_number.size();
    vector<long long> answer (size, 0);
    map<int, bool> room_check;
    long long first_room = 1;
    

    for(int i=0; i<size; i++){
        if(!room_check[room_number[i]]){ // 바로 가능
            room_check[room_number[i]] = true;
            answer[i] = room_number[i];
        }
        else{
            for (int j=room_number[i]+1; j<=k; j++){
                if(!room_check[j]){
                    room_check[j] = true;
                    answer[i] = j;
                    break;
                }
            }
        }
        
    }
    return answer;
}