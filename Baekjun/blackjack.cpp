#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> numbers;
    for(int i=0; i<N; i++){
        int t;
        cin >> t;
        numbers.push_back(t);
    }
    int answer = 0;
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    vector<int>::iterator it3;
    for(it1=numbers.begin(); it1 != numbers.end()-2; it1++){
        for(it2 = it1+1; it2 != numbers.end()-1; it2++){
            for(it3 = it2+1; it3 != numbers.end(); it3++){
                int result = *it1 + *it2 + *it3;
                if(result > answer && result <= M)
                    answer = result;
            }
        }
    }
    cout << answer << endl;
    return 0;
}