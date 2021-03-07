#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        bool first_letter = false;
        bool second_letter = true;
        for(int i=0; i<len; i++){
            int _c = word[i];
            cout << word[i] << endl;
            if(i == 0 && _c >=65 && _c <=90) first_letter = true;
            if(i == 1 && _c >=97) second_letter = false;
            if(first_letter == true){
                if(second_letter == true && _c>=65 && _c<=90) // capital
                    continue;
                else if (second_letter == false && _c>=97)
                    continue;
                else return false;
            }
            else{
                if(_c>=97)
                    continue;
                else return false;
            }
        }
        return true;
    }
};

int main()
{
    string word = "GldL";
    Solution s;
    if(s.detectCapitalUse(word) == true) cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;

}