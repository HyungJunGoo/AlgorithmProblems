/**
 * Implement the StreamChecker class as follows:

    StreamChecker(words): Constructor, init the data structure with the given words.
    query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, 
    including this letter just queried) spell one of the words in the given list.
 

    Example:

    StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
    streamChecker.query('a');          // return false
    streamChecker.query('b');          // return false
    streamChecker.query('c');          // return false
    streamChecker.query('d');          // return true, because 'cd' is in the wordlist
    streamChecker.query('e');          // return false
    streamChecker.query('f');          // return true, because 'f' is in the wordlist
    streamChecker.query('g');          // return false
    streamChecker.query('h');          // return false
    streamChecker.query('i');          // return false
    streamChecker.query('j');          // return false
    streamChecker.query('k');          // return false
    streamChecker.query('l');          // return true, because 'kl' is in the wordlist
*/



#include <bits/stdc++.h>
using namespace std;

class StreamChecker {
    unordered_map<char, bool> char_dictionary;
public:
    StreamChecker(vector<string>& words) {
        for(string word : words){
            if(char_dictionary[word[word.length()-1]] == true)continue;
            else char_dictionary[word[word.length()-1]] = true;
        }
    }
    
    bool query(char letter) {
        if(char_dictionary[letter] == true) return true;
        else return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main()
{

    return 0;
}