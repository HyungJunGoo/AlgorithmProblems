#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > rotate(vector<vector<int> > key, int m){
    vector<vector<int> > r_key (m, vector<int> (m, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            r_key[j][m-1-i]=key[i][j];
        }
    }
    return r_key;

}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int m = key.size();
    int n = lock.size();

    vector<vector<int> > answer_key (n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(lock[i][j] == 0)
                answer_key[i][j] = 1;
        }
    }
    for(int r=1; r<=4; r++){//for rotate
       
        key = rotate(key, m);
    }
    return false;
}