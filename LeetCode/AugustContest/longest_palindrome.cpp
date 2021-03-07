#include <bits/stdc++.h>
using namespace std;
bool mysort(pair<char,int> &a, pair<char,int> &b){
    return a.second > b.second; 
}
class Solution {
public:
    unordered_map<char, int> c_m;
    int longestPalindrome(string s) {
        int l = s.length();
        if(l == 0 || l == 1) return l;
        for(int i=0; i<l; i++){
            if(!c_m[s[i]])
                c_m[s[i]] = 1;
            else
                c_m[s[i]]++;
        }
        int len = 0;
        unordered_map<char, int>::iterator itr;
        vector<pair<char,int> > odd_char;
        for(itr = c_m.begin(); itr != c_m.end(); itr++){
            if( (*itr).second % 2 == 1)
                odd_char.push_back(make_pair((*itr).first , (*itr).second));
        }
        sort(odd_char.begin(), odd_char.end(), mysort);
        int odd_char_len = odd_char.size();
        char longest_char;
        
        if(odd_char_len > 0) longest_char = odd_char[0].first;
    
        for(itr = c_m.begin(); itr != c_m.end(); itr++){
            if((*itr).second % 2==1){ // odd
                if(odd_char_len > 0 && (*itr).first == longest_char){
                    len += (*itr).second;
                }
                else if(odd_char_len > 1 && (*itr).second %2 == 1 ){
                    len += (*itr).second-1;
                }
            }
            else{ // even
                len += (*itr).second;
            }
        }
        return len;
    }
};

int main()
{
    Solution s;
    string str = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}