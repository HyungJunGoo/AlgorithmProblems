#include <bits/stdc++.h>

using namespace std;

struct Trie{
    bool leaf;
    int count;
    Trie* next[26];

    Trie(){
        leaf = false;
        count = 1;
        fill(next, next+26, nullptr);
    }
    ~Trie(){
        for(int i=0; i<26; i++)
            if(next[i]) delete next[i];
    }

    void insert(const char* key ){
        if(*key=='\0'){
            leaf = true;
            return;
        } //base case

        int next_char_idx = *key - 'a';
        if(next[next_char_idx] == nullptr)
            next[next_char_idx] = new Trie();
        else next[next_char_idx]->count++;
        next[next_char_idx]->insert(key+1);
    }

    int find(const char* key){
        int curr = *key - 'a';
        if(*key == '?'){
            int tmp = 0;
            for (int j=0; j<26; j++){
                if(next[j] != nullptr)
                    tmp += next[j]->count;
            }
            return tmp;
        }
        if(next[curr] == nullptr) return 0;
        if(*(key+1) == '?') return next[curr]->count;
        return next[curr]->find(key+1);
    }
};


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer (queries.size(), 0);

    Trie* trie [100001];
    Trie* r_trie [100001];

    for(string str : words){
        int l = str.length();
        if(!trie[l]) trie[l] = new Trie();
        trie[l]->insert(str.c_str());

        reverse(str.begin(), str.end());
        if(!r_trie[l]) r_trie[l] = new Trie();
        r_trie[l]->insert(str.c_str());
    }
    int i=0;
    for (string query : queries){
        int l = query.length();
        if (query[0] == '?'){
            reverse(query.begin(), query.end());
            if(!r_trie[l]){
                i++;
                continue;
            }
            answer[i++] = r_trie[l]->find(query.c_str());
        }else{
            if(!trie[l]){
                i++;
                continue;
            }
            answer[i++] = trie[l]->find(query.c_str());
        }
    }
    return answer;
}