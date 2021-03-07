#include <bits/stdc++.h>

using namespace std;

int change_num(string time){
    int number = 0;
    number = stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
    return number;
}

string change_time(int time){
    int h = time / 60;
    int m = time % 60;
    string str = "";
    if (h < 10){
        str += '0';        
    }
    str += to_string(h) + ':';
    if( m < 10)
        str += '0';
    str += to_string(m);
    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int cone_time = 0;
    map<int, vector<int> > bus_time;
    int crew_number = timetable.size();
    vector<int> bus_time_vector (n);
    // Set Bus Time Table
    int start_time = 540; // 09:00
    for(int i=0; i<n; i++){
        bus_time[start_time + i*t] = {};
        bus_time_vector[i] = start_time + i*t;
    }
    vector<int> num_timetable = {};
    for(int i=0; i<crew_number; i++){
        int crew_time = change_num(timetable[i]);
        num_timetable.push_back(crew_time);
    }
    
    sort(num_timetable.begin(), num_timetable.end());
    
    queue<int> q_num_timetable;
    for(int t : num_timetable){
        q_num_timetable.push(t);
    }
    
    for(int i=0; i<n; i++){
        int cnt=1; // cannot be bigger than m
        int bus_arrive = bus_time_vector[i];
        while(cnt <= m && !q_num_timetable.empty() && q_num_timetable.front() <= bus_arrive){
            int q_front = q_num_timetable.front();
            bus_time[bus_arrive].push_back(q_front);
            q_num_timetable.pop();
            cnt++;
        }
    }
    // 마지막 차 만차로 출발하는 지 확인
    if(bus_time[bus_time_vector[n-1]].size() == m){// 만차로 출발
        map<int, int> last_bus_group;
        for(int time : bus_time[bus_time_vector[n-1]]){
            if(!last_bus_group[time])
                last_bus_group[time] = 1;
            else
                last_bus_group[time] ++;
        }
        int people = 0;
        for(auto time_x : last_bus_group){
            people += time_x.second;
            if(people >= m)
                cone_time = time_x.first-1;
        }
    }
    else{ // 자리 있음
        cone_time = bus_time_vector[n-1];
    }
    answer = change_time(cone_time);
    return answer;
}