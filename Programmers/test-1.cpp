#include <bits/stdc++.h>

using namespace std;

int main() 
{
    map <int, int > m;
    m[0] = 0;
    m[1] = 1;
    m.erase(m.find(1));
    for(auto i : m)
        cout << i.first << endl;
    cout << m.size() << endl;
    int n = (*m.begin()).first;
    m.erase(m.find(n));
    cout << m.size() << endl;
    return 0;
}