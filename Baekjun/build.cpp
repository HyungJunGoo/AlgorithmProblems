#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int> > people(N);
    for(int i=0; i<N; i++){
        int t1, t2;
        cin >> t1 >> t2; // weight and height
        people[i] = make_pair(t1,t2); 
    }
    vector<int> answer;
    for(int i=0; i<N; i++){
        int number = 0;
        for(int j=0; j<N; j++){
            if(i == j) continue;
            if(people[i].first < people[j].first && people[i].second < people[j].second) number++;
        }
        answer.push_back(number+1);
    }

    for(auto n : answer)
        cout << n << ' ';
    cout << endl;
    return 0;
}