/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
A . means it can represent any one letter.

Example
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true
*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    map<int, vector<string> > data;
    WordDictionary() {

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int l = word.length();
        data[l].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int l = word.length();
        bool result = false;
        for(auto w : data[l]){
            for(int i=0; i<l; i++){
                if(word[i] == '.'){
                    if(i == l-1)
                        return true;
                    continue;
                }
                if(word[i] != w[i])
                    break;
                if(i == l-1)
                    result = true;
                if(result == true)
                    return result;
            }
        }
        return result;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("runner");
    obj->addWord("ran");
    bool p = obj->search("ru.n.e");
    if(p == true) cout << "true" << endl;
    else cout << "false"<< endl;

    return 0;
}