#include <bits/stdc++.h>

using namespace std;

void split_log(string log, vector<pair<int, int> >& log_list){
    int l = log.length();
    string date = "";
    string finish_time = "";
    string taken_time = "";
    vector<string> s_vec = {};
    string s = "";
    for(int i=0; i<l; i++){
        if(log[i] == ' '){
            s_vec.push_back(s);
            s = "";
        }
        else
            s+=log[i];
    }
    finish_time = s_vec[1];
    taken_time = s.substr(0, s.length()-1);
    vector<string> date_vect = {};
    s = "";
    for(int i=0; i<finish_time.length(); i++){
        if(finish_time[i] == ':'){
            date_vect.push_back(s);
            s = "";
        }
        else
            s+=finish_time[i];
    }
    date_vect.push_back(s);

    int m_hour = stoi(date_vect[0]) * 1000;
    int m_min = stoi(date_vect[1]) * 1000;
    s = "";
    int m_sec_front;
    int m_sec_back;
    for(int i = 0; i < date_vect[2].length(); i++){

        if(date_vect[2][i] == '.'){
            m_sec_front = stoi(s) * 1000;
            s="";
        }
        else
            s += date_vect[2][i];            
    }
    m_sec_back = stoi(s);
    
    s = "";
    int m_taken_sec_front;
    int m_taken_sec_back;
    vector<string> divide_dot = {};
    for(int i=0; i<taken_time.length(); i++){
        if(taken_time[i] == '.'){
            divide_dot.push_back(s);
            s = "";
        }
        else
            s += taken_time[i];
    }
    divide_dot.push_back(s);
    if(divide_dot.size() == 1){
        m_taken_sec_front = stoi(divide_dot[0]) * 1000;
        m_taken_sec_back = 0;
    }
    else{
        m_taken_sec_front = stoi(divide_dot[0]) * 1000;
        m_taken_sec_back = stoi(divide_dot[1]);
    }
    int converted_finish_time = m_hour * 3600 + m_min * 60 + m_sec_front + m_sec_back;
    int converted_start_time = converted_finish_time - (m_taken_sec_front+m_taken_sec_back) + 1;
    log_list.push_back(make_pair(converted_start_time, converted_finish_time));
}

int count_logs(vector<pair<int, int> > log_dict, int time){
    int time_end = time + 1000;
    int count = 0;

    for(auto p : log_dict){
        if (!( p.first >= time_end || p.second < time))
            count += 1;
    }
    return count;
}

int solution(vector<string> lines) {
    vector<pair<int, int> > log_dict;
    int max_count = 0;
    for(auto line : lines)
        split_log(line, log_dict);
    for (auto p : log_dict)
        cout << p.first << " " << p.second << endl;
    for (auto p: log_dict){
        int p_first = count_logs(log_dict, p.first);
        int p_second = count_logs(log_dict, p.second);
        if(max(p_first, p_second) > max_count)
            max_count = max(p_first, p_second);
    }
    cout << max_count << endl;
    return max_count;
}

int main(){
    int answer = solution({"2016-09-15 01:00:04.002 2.0s","2016-09-15 01:00:07.000 2s"});
    int answer2 = solution({"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"});
}