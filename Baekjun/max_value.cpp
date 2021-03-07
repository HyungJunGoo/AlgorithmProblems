#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    int order = 1;
    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;
        m[n] = order;
        order++;
    }
    int max = (*max_element(m.begin(), m.end())).first;
    int w = (*max_element(m.begin(), m.end())).second;
    cout << max << " " << w << endl;
    return 0;
}


/*
3
29
38
12
57
74
40
85
61
*/