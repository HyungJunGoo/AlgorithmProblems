#include <bits/stdc++.h>

using namespace std;

int int_time_change(string time){
    
    int hour = stoi(time.substr(0,2)) * 3600;
    int min = stoi(time.substr(3,2)) * 60;
    int sec = stoi(time.substr(6,2));

    return (hour+min+sec);
}

string str_time_change(int time){
    if(time == 0)
        return "00:00:00";
    string hour = "";
    string min = "";
    string sec = "";
    hour += to_string(time/3600);
    if(hour.length() == 1) 
        hour = '0' + hour;
    min += to_string((time%3600)/60);
    if(min.length() == 1) 
        min = '0' + min;
    sec += to_string((time%3600)%60);
    if(sec.length() == 1) 
        sec = '0' + sec;
    return (hour + ':' + min + ':' +sec);
}

vector<int> total_time (360000, 0);

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int logs_size = logs.size();
    int ad_time = int_time_change(adv_time);
    int play_time_ = int_time_change(play_time);
    for(int i = 0; i<logs_size; i++){
        int logs_start = int_time_change(logs[i].substr(0,8));
        int logs_end = int_time_change(logs[i].substr(9,8));
        total_time[logs_start] += 1;
        total_time[logs_end] -= 1;
    }

    // total_time 재정의
    // total_time[x] = x-1부터 x까지  1초 동안 을 따졌을 때 임의의 x초에 대해서 그 순간 보고있는 로그의 수를 반영시킴
    for(int i=1; i<play_time_; i++){
        total_time[i] = total_time[i] + total_time[i-1];
    }

    // total_time 재정의
    // total_time[x] = 임의의 x 초 까지  누적된 재생시간
    // 
    for(int i=1; i<play_time_; i++){
        total_time[i] = total_time[i] + total_time[i-1];
    }
    int max_time = 0;
    int max_time_log = 0;
    int at = ad_time;
    for(int i=ad_time-1; i<play_time_; i++){
        if (i >= at){
            if(max_time < total_time[i]-total_time[i-at]){
                max_time = max(max_time, total_time[i]-total_time[i-at]);
                max_time_log = i-at+1;
            }
        }
        else{
            max_time = max(max_time, total_time[i]);
            max_time_log = i-at+1;
        }
    }
    answer = str_time_change(max_time_log);
    return answer;
}