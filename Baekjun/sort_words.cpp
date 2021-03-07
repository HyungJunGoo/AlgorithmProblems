/*
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

1.길이가 짧은 것부터
2.길이가 같으면 사전 순으로
*/

#include <bits/stdc++.h>
using namespace std;

bool mysort(string &a, string &b){
    if(a.length() == b.length() )
        return a<b;
    else
        return a.length() < b.length();
}

int main()
{
    int N; cin >> N;
    vector<string> dict;
    map<string, int> listed;
    for(int i=0; i<N; i++){
        string word;
        cin >> word;
        if(!listed[word]){
            dict.push_back(word);
            listed[word]=1;
        }
    }
    cout << "----------------" << '\n';
    sort(dict.begin(), dict.end(), mysort);
    for(auto word : dict)
        cout << word << '\n';
    return 0;
}