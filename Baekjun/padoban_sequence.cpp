#include <bits/stdc++.h>
using namespace std;
unsigned long long int arr[100];
void padoban(){
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 2;
    for(int i = 5; i<100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }
}

int main()
{
    int N;
    cin>>N;
    vector<long long int> answer;
    padoban();
    for(int i=0; i<N; i++){
        int t;
        cin >> t;
        answer.push_back(arr[t-1]);
    }
    for(auto n : answer)
        cout << n << endl;
    return 0;
}
