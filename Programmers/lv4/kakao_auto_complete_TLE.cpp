#include<bits/stdc++.h>

using namespace std;

int get_common_length(string str1, string str2){
	int iter_length = min(str1.length(), str2.length());
	int common_l = 0;
	for(int i=0; i<iter_length; i++){
		if(str1[i] == str2[i])
			common_l++;
		else
			return common_l;
	}
	return common_l;
}

int solution(vector<string> words) {
    int answer = 0;
	vector<pair<string, int>> checked_words;
	checked_words.clear();
	checked_words.push_back(make_pair(words[0], 1));
	
	// for (auto word : checked_words)
	// 	cout << word.first << word.second<< endl;
	for(int i = 1; i<words.size(); i++){
        int val = 0;
        for(int j = 0; j<checked_words.size(); j++)
		{
            // cout << "comparing word : " << word.first  << "&" << word.second << endl;
			int common_l = get_common_length(checked_words[j].first, words[i]);
			// cout << "common Len : " << common_l << endl;
            if (common_l == 0){
                continue;
            }
			if (checked_words[j].second <= common_l){
                if (checked_words[j].first.length() == common_l){
                    checked_words[j].second = common_l;
                    // cout << "word " << word.first << " : " << word.second << endl;
                }  
			    else
				    checked_words[j].second = common_l+1;    
            }
            val = max(val, common_l);
		}
        if( words[i].length() > val)
			val++;
		checked_words.push_back((make_pair(words[i], val)));
        
	}
	for (auto word : checked_words)
		answer += word.second;

    return answer;
}