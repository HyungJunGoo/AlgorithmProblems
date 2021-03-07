#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

vector<int> v(MAX);
bool func(string str){
    int len = str.length();
    for(int i=0; i<len-2; i++){
        if(str.substr(i,3) == "666")
            return true;
    }
    return false;
}
int main()
{
    int N;
    cin >> N;
    int n = 666;
    int size = 1;
    v[1] = n++;

    while (size != N)
    {
        if(func(to_string(n)) == true){
            v[size+1] = n;
            size++;
        }
        n++;
    }
    // for(int i=1; i<=N; i++)
    //     cout << v[i] << endl;
    cout << v[N] << endl;
    return 0;
}