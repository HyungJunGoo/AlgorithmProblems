#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    int size = room_number.size();
    vector<long long> answer (size, 0);
    map<long long, bool> room_check;
    long long first_room = 1;
    

    for(int i=0; i<size; i++){
        if(!room_check[room_number[i]]){
            room_check[room_number[i]] = true;
            answer[i] = room_number[i];
            if( answer[i] == first_room){
                for(long long j=first_room+1; j<=k; j++){
                    if(!room_check[j]){
                        first_room = j;
                        break;
                    }
                }
            }
                
        }
        else{ // 원하는 방에 예약이 안될 때
            if(room_number[i] > first_room){
                for(long long j=room_number[i]+1; j<=k; j++){
                    if(!room_check[j]){
                        room_check[j] = true;
                        answer[i] = j;
                        break;
                    }
                }
            }
            else{
                answer[i] = first_room;
                room_check[first_room] = true;
                for(long long j=first_room+1; j<=k; j++){
                    if(!room_check[j]){
                        first_room = j;
                        break;
                    }
                }
            }
        }
        // cout << first_room << endl;
    }
    return answer;
}