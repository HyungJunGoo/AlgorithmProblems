#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    int cnt;
    bool leaf;
    Trie* next[26];
    
    Trie(){
        cnt = 0;
        leaf = false;
        fill(next, next+26, nullptr);
    }

    void insert(const char* key){
        if((*key)=='\0'){
            cnt += 1;
            leaf = true;
            return;
        } // basecase

        int next_char_idx = *key - 'a';
        if (next[next_char_idx] == nullptr){
            next[next_char_idx] = new Trie();
        }
        cnt += 1;
        next[next_char_idx]->insert(key + 1);
    }

};

int find(Trie* trie, const char* word, int idx){
    if ((*word) == '\0')
        return idx;

    if (trie->cnt==1)
        return idx;

    int next_char_idx = *word - 'a';

    if(trie->next[next_char_idx])
        return find(trie->next[next_char_idx], word+1, idx+1);
}

int solution(vector<string> words){
    int answer = 0;
    Trie* trie = new Trie();

    for (string word : words){
        trie->insert(word.c_str());
    }
    for (string word : words){
        answer += find(trie, word.c_str(), 0);
    }
    return answer;
}