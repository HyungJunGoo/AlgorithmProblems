#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d = {1,3,2,5};
    sort(d.begin(), d.end());
    cout << d[1] << endl;
    cout << d.back() << endl;

    return 0;
}