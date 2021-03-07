#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int answer = 0;
    vector<string> words;
    for(int i=0;i<num;i++){
        string word;
        cin >> word;
        words.push_back(word);
    }   
    for(int i=0; i<num; i++){
        queue<char> q;
        map<char, int> check_list;
        for(auto c : words[i])
            q.push(c);
        bool check = true;
        char prev = q.front();
        q.pop();
        while (q.empty() == false)
        {
            if(q.front() != prev){
                if(check_list[q.front()]){
                    check = false;
                    break;
                }
                check_list[prev] = 1;
                prev = q.front();
                q.pop();
            }
            else q.pop();
        }
        if( check == true) answer++;
    }
    cout << answer << endl;
    return 0;
}
