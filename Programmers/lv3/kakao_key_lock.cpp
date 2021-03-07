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
vector<vector<int> > move(vector<vector<int> > key, int m, int direction, int l){ 
    if(l==0) // not moving
        return key;

    vector<vector<int> > m_key (m, vector<int> (m, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            switch (direction)
            {
            case 0:
                // up
                if(i < m-l)
                    m_key[i][j] = key[i+l][j];
                else m_key[i][j] = 0;
                break;
            case 1:
                // down
                if (i > l-1)
                    m_key[i][j] = key[i-l][j];
                else m_key[i][j] = 0;
                break;
            case 2:
                // left
                if(j < m-l)
                    m_key[i][j] = key[i][j+l];
                else m_key[i][j] = 0;
                break;
            case 3:
                // right
                if(j > l-1)
                    m_key[i][j] = key[i][j-l];
                else m_key[i][j] = 0;
                break;
            }
        }
    }
    return m_key;
}

bool key_compare(vector<vector<int> > padded_key, vector<vector<int> > padded_lock, int m, int n){
    for(int i=0; i<n+m-1; i++){
        for(int j=0; j<n+m-1; j++){
            if(padded_lock[i][j] == -1)
                continue;
            if(padded_lock[i][j] == 1 && padded_key[i][j] == 1)
                return false;
            if(padded_lock[i][j] == 0 && padded_key[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool key_moving(vector<vector<int> > padded_key, vector<vector<int> > padded_lock, int m, int n){
    for(int i=0; i < n+m-1; i++){
        vector<vector<int> > tmp_padded_key = padded_key;
        for(int j=0; j<n+m-1; j++){
            if(key_compare(padded_key, padded_lock, m, n) == true)
                return true;
            padded_key = move(padded_key, padded_key.size(), 3, 1);
        }
        padded_key = tmp_padded_key;
        padded_key = move(padded_key, padded_key.size(), 1, 1);
    }
    return false;
}

vector<vector<int> > padding_lock(vector<vector<int> > lock, int m, int n){
    vector<vector<int> > padded_lock (n+m*2-2, vector<int> (n+m*2-2, -1));
    for(int i=m-1; i<m-1+n; i++){
        for(int j=m-1; j<m-1+n; j++){
            padded_lock[i][j] = lock[i-m+1][j-m+1];
        }
    }
    return padded_lock;
}
vector<vector<int> > padding_key(vector<vector<int> > key, int m, int n){
    vector<vector<int> > padded_key (n+m*2-2, vector<int> (n+m*2-2, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            padded_key[i][j] += key[i][j];
        }
    }
    return padded_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int m = key.size();
    int n = lock.size();

    vector<vector<int> > padded_lock = padding_lock(lock, m, n);
    vector<vector<int> > padded_key = padding_key(key, m, n);
    for(int r=1; r<=4; r++){//for rotate
        vector<vector<int> > padded_key = padding_key(key, m, n);
        if(key_moving(padded_key, padded_lock, m, n) == true){
            return true;
        }
        key = rotate(key, m);
    }
    return false;
}