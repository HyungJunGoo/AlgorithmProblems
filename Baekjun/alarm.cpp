#include <iostream>

using namespace std;

int main()
{
    int H,M; // 0<= H < = 23, 0<=M <=59
    cin >> H >> M;
    int re = M - 45;
    if(re < 0 ){
        M = 60 - (re*-1);
        H -=1;
        if(H < 0){
            H = 23;
            cout << H << " " << M <<endl;
        }
        else
            cout << H << " " << M <<endl;
    }
    else
        cout << H << " " << re <<endl;
    return 0;
}