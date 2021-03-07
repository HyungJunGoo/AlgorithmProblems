#include <bits/stdc++.h>
using namespace std;

int divide_and_sum(int N){
    int len = to_string(N).length();
    int result = N;
    for(int i=0; i<len; i++){
        result += (to_string(N)[i]) - '0';
    }
    return result;
}

void func(int N){
    bool find = false;
    for(int i=1; i<N; i++){
        if(divide_and_sum(i) == N){
            find = true;
            cout << i << endl;
            return;
        }
    }
    if( find == false) cout << 0 << endl;
}
int main()
{
    int N;
    cin >> N;
    func(N);
    return 0;
}