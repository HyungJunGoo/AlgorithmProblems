#include <bits/stdc++.h>

using namespace std;

string sharp_conversion(string melody){
	string conv_melody = "";
	for(int i=0; i<melody.length(); i++){
		
		if(melody[i] == '#'){
			switch(melody[i-1]){
				case 'C':
					conv_melody += '1';
                    break;
				case 'D':
					conv_melody += '2';
                    break;
				case 'F':
					conv_melody += '3';
                    break;
				case 'G':
					conv_melody += '4';
                    break;
				case 'A':
					conv_melody += '5';
                    break;
                case 'E':
                    conv_melody += '6';
                    break;
                case 'B':
                    conv_melody += '7';
                    break;
			}
		}
		else{
            if (i != melody.length()-1 && melody[i+1] != '#')
			    conv_melody += melody[i];
            else
                continue;
        }
	}
	if (melody[melody.length()-1] != '#')
		conv_melody += melody[melody.length()-1];
	return conv_melody;
}

bool check(string full_contents, string m){
	
	if (full_contents.find(m) != string::npos){
		return true;
	}
	
	return false;
}

string solution(string m, vector<string> musicinfos){
	string answer = "";
	m = sharp_conversion(m);
	vector<pair<string, int>> candidate;
    candidate.clear();
	for(auto info : musicinfos){
		vector<string> temp_music_info;
		stringstream s (info);
		while(s.good()) {
			string substr;
			getline(s, substr, ',');
			temp_music_info.push_back(substr);
		}
		string start_t = "", end_t = "";
		string title = "";
		string contents = "";
		
		start_t = temp_music_info[0];
		end_t = temp_music_info[1];
		title = temp_music_info[2];
		contents = sharp_conversion(temp_music_info[3]);
		int play_len = 0;
		int contents_len = contents.length();
		int l_h=0, l_m = 0;
		string sub_str_s_h = start_t.substr(0,2);
		string sub_str_s_m = start_t.substr(3,2);
		string sub_str_e_h = end_t.substr(0,2);
		string sub_str_e_m = end_t.substr(3,2);
		l_h = stoi(sub_str_e_h) - stoi(sub_str_s_h);
		l_m = stoi(sub_str_e_m) - stoi(sub_str_s_m);
        
        
		int taken_time = l_h * 60 + l_m;
		int iteration = taken_time/contents_len;
        int last = taken_time % contents_len;
		string full_contents = "";
        if(iteration > 0){
            for(int i=0; i<iteration; i++){
                full_contents += contents;
            }
        }
        
        full_contents += contents.substr(0, last);
        
		
		if ( check(full_contents, m)){
			candidate.push_back(make_pair(title, taken_time));	
		}
	}
    if(candidate.size() == 0)
        return "(None)";
	int longest_length = 0;
	string longest_length_title = "";
	for (auto p : candidate){
		if(p.second > longest_length){
			longest_length = p.second;
			longest_length_title = p.first;
		}	
	}	
	answer = longest_length_title;
	return answer;
}

int main(){
	string result = solution("ABCDEFG", {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"});
	cout << result << endl;
	return 0;
}
