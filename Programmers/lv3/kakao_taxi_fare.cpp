#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    

    vector<vector<int> > minDistance (n+1, vector<int> (n+1, INT16_MAX));
    for(int i=1; i<=n; i++)
        minDistance[i][i] = 0;
    
    for(int i=0; i<fares.size(); i++){
        // fares[i] = {u, v, fare}
        int u = fares[i][0];
        int v = fares[i][1];
        int fare = fares[i][2];

        minDistance[u][v] = fare;
        minDistance[v][u] = fare;
    }

    for(int mid=1; mid<=n; mid++){
        for(int start=1; start<=n; start++){
            for(int dest=1; dest<=n; dest++){
                if(minDistance[start][dest] > minDistance[start][mid] + minDistance[mid][dest])
                    minDistance[start][dest] = minDistance[start][mid] + minDistance[mid][dest];
            }
        }
    }
    int answer = minDistance[s][a] + minDistance[s][b];
    for(int i=1; i<=n; i++){
        if(i == s || i == a || i == b) continue;
        answer = min(answer, minDistance[s][i] + minDistance[i][a] + minDistance[i][b]);
    }

    return answer;
}