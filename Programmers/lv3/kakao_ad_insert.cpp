// Not Solved

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

int check_log_time(int start_time, int ad_time, map<int, pair<int, int> > log_map){
    int end_time = start_time + ad_time;
    int total_ad_seen_time = 0;
    for(auto m : log_map){
        int ad_seen_time = 0;
        if(m.second.first >= start_time && m.second.first < end_time){
            if(m.second.second > end_time){
                ad_seen_time += (end_time - m.second.first);
            }
            else{ // m.second.second <= end_time
                ad_seen_time += (m.second.second - m.second.first);
            }
        }
        total_ad_seen_time += ad_seen_time;
    }
    return total_ad_seen_time;
}


string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int ad_time = int_time_change(adv_time);
    map<int, pair<int, int> > log_map;
    for(int i=0; i<logs.size(); i++){
        cout << logs[i] << endl;
        log_map[i+1] = make_pair(int_time_change(logs[i].substr(0,8)), int_time_change(logs[i].substr(9,8)));
    }
    int max_seen_time = 0;
    int max_seen_time_start_time = 0;
    if(int_time_change(play_time) == ad_time){
        int init_play_time_case = check_log_time(0, ad_time, log_map);
        cout << "init case " << init_play_time_case << endl;
        if(init_play_time_case > max_seen_time){
            max_seen_time = init_play_time_case;
            max_seen_time_start_time = 0;
        }
    }
    for(auto m : log_map){
        int m_seen_time = check_log_time(m.second.first, ad_time, log_map);
        // cout << m.first << "'s case : " << m_seen_time << endl;
        cout << m.first << "'s case : " << m.second.first << "," << m.second.second << endl;
        if (m_seen_time > max_seen_time){
            max_seen_time = m_seen_time;
            max_seen_time_start_time = m.second.first;
        }
        else if(m_seen_time == max_seen_time){
            if(m.second.first < max_seen_time_start_time)
                max_seen_time_start_time = m.second.first;
        }
    }
    answer = str_time_change(max_seen_time_start_time);

    return answer;
}