/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.

A function next() that returns the next combination of length combinationLength in lexicographical order.

A function hasNext() that returns True if and only if there exists a next combination.

Example
    CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

    iterator.next(); // returns "ab"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "ac"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "bc"
    iterator.hasNext(); // returns false
*/

#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
    vector<char> char_list;
    set<string> candidate_set;
    deque<string> candidate;
public:

    CombinationIterator(string characters, int combinationLength) {
        for(char c : characters)
            char_list.push_back(c);
        int n = characters.length();
        vector<int> ind ; //for index 0,1 

        for(int i=0; i<combinationLength; i++)
            ind.push_back(1);
        for(int i=0; i<n-combinationLength; i++)
            ind.push_back(0);
        sort(ind.begin(), ind.end());
        do
        {
            string tmp = "";
            for(int i=0; i<n; i++){
                if(ind[i]==1)
                    tmp += char_list[i];
            }
            candidate_set.insert(tmp);
        } while (next_permutation(ind.begin(), ind.end()));
        set<string>::iterator itr;

        for(itr=candidate_set.begin(); itr != candidate_set.end(); itr++)
            candidate.push_back(*itr);

    }
    string next() {
       string next = candidate.front();
       candidate.pop_front();
       return next;
       
    }
    
    bool hasNext() {
       if(candidate.size()>0) return true;
       else return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    CombinationIterator* obj = new CombinationIterator("abc", 2);
    string param_1 = obj->next();
    cout << param_1 << endl;
    
    bool param_2 = obj->hasNext();
    if(param_2 == true) cout << "true" << endl;
    else cout << "false" << endl;
    
    string param_3 = obj->next();
    cout << param_3 << endl;

    string param_4 = obj->next();
    cout << param_4 << endl;

    bool param_5 = obj->hasNext();
    if(param_5 == true) cout << "true" << endl;
    else cout << "false" << endl;
    // obj->getelement();
    return 0;
}