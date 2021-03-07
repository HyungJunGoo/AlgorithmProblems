#include <bits/stdc++.h>

using namespace std;

long long find(map<long long, long long> & room_check, long long room_number)
{
    if(room_check[room_check[room_number]]){
        room_check[room_number] = find(room_check, room_check[room_number]);
        return room_check[room_number];
    }
    else{
        room_check[room_check[room_number]] = room_check[room_number] + 1;
        return room_check[room_number];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    int size = room_number.size();
    vector<long long> answer (size, 0);
    map<long long, long long> room_check;
    for(int i=0; i<size; i++){
        if(!room_check[room_number[i]]){ // 빈 방
            room_check[room_number[i]] = room_number[i]+1; // next room
            answer[i] = room_number[i];
        }
        else{
            answer[i] = find(room_check, room_number[i]);
        }
    }

    return answer;
}