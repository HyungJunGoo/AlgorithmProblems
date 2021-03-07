#include <bits/stdc++.h>
using namespace std;

bool mysort(string &a, string &b){
    return a.length() > b.length();
}

class word_math
{
public:
    int get_maximum_um(int num, vector<string> words){
        map<int , vector<char>> char_position;
        unordered_map<char, int> char_num;

        sort(words.begin(), words.end(), mysort);
        int max_l = words[0].length()-1;
        int first = 9;
        for(string word : words){
            for(int i=word.length()-1; i>=0; i--){
                char_position[i].push_back(word[word.length()-1-i]);
            }
        }

        for(int i=max_l; i>=0; i--){
            for(char c : char_position[i]){
                if(!char_num[c]){
                    char_num[c] = first;
                    first--;
                }
            }
        }

        int result=0;
        for(string word : words){
            string s_tmp = "";
            for(char c : word){
                s_tmp +=  to_string(char_num[c]);
            }
            result += stoi(s_tmp);
        }

        return result;
    }

};

int main()
{
    int num_of_words;
    cin >> num_of_words;
    vector<string> words;
    for(int i=0; i<num_of_words; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }
    word_math w_m;
    cout << w_m.get_maximum_um(num_of_words, words) << endl;

    return 0;
}