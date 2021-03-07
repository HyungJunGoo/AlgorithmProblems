#include <bits/stdc++.h>

using namespace std;

int main(){

    int answer = 0;
    int N, L;
    cin >> N >> L;
    vector<vector<int> > map_info (N, vector<int> (N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int n;
            cin >> n;
            map_info[i][j] = n;
        }
    }
    
    vector<vector<int> > h_delta_horizon (N, vector<int> (N));
    vector<vector<int> > h_delta_vertical (N, vector<int> (N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j==0)
                h_delta_horizon[i][j] = 0;
            else{
                h_delta_horizon[i][j] = map_info[i][j] - map_info[i][j-1];
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j==0)
                h_delta_vertical[j][i] = 0; 
            else{
                h_delta_vertical[j][i] = map_info[j][i] - map_info[j-1][i];
            }
        }
    }

    // for(auto v : h_delta_vertical){
    //     for(int n : v)
    //         cout << n << " ";
    //     cout << endl;
    // }

    // iterate horizon
    for(int i=0; i<N;i++){
        bool possible = true;
        vector<int> check_cline (N, 0);
        for(int j=1; j<N; j++){
            if(abs(h_delta_horizon[i][j]) > 1){
                cout << "impossible" << i <<"," << j << endl;
                possible = false;
                break;
            }
            else if(h_delta_horizon[i][j] == 0){ // 동일 높이
                continue;
            }
            else if(h_delta_horizon[i][j] == 1){ // 상승
                if(L == 1) {
                    if(check_cline[j-1] == 0){ 
                        check_cline[j-1] = 1;
                        continue;
                    }
                    else{
                        possible = false;
                        cout << "impossible" << i <<"," << j << endl;
                        break;
                    }
                }
                int k = j-1;
                int cnt=0;
                while(cnt < L&& k>=0){
                    if(map_info[i][k] == map_info[i][j]-1 && check_cline[k] == 0){
                        check_cline[k] = 1;
                        cnt++;
                    }
                    else break;
                    k--;
                }
                if(cnt == L){
                    continue;
                }
                else{
                    cout << "impossible" << i <<"," << j << endl;
                    possible = false; 
                    break;
                }
            }
            else if (h_delta_horizon[i][j] == -1){ // 감소"
                if(L == 1) {
                    if(check_cline[j] == 0){
                        check_cline[j] = 1;
                        continue;
                    }
                    else{
                        possible = false;
                        cout << "impossible" << i <<"," << j << endl;
                        break;
                    }
                }
                int k = j+1;
                int cnt=0;
                while(cnt < L-1 && k<N){
                    if(map_info[i][k] == map_info[i][j] && check_cline[k] == 0){
                        check_cline[k] = 1;
                        cnt++;
                    }
                    else break;
                    k++;
                }
                if(cnt == L-1)
                    // 겹치는 경사로 아니면 가능
                    continue;
                else {
                    cout << "impossible" << i <<"," << j << endl;
                    possible = false;
                    break;
                }
            }
        }
        if(possible == true){
            answer++;
        }
        // 가능한 길
    }
    cout << "Vertical iteration" << endl;
    // iterate vertical
    for(int i=0; i<N;i++){
        bool possible = true;
        vector<int> check_cline (N, 0);
        for(int j=1; j<N; j++){
            if(abs(h_delta_vertical[j][i]) > 1){
                cout << "impossible" << i <<"," << j << endl;
                possible = false;
                break;
            }
            else if(h_delta_vertical[j][i] == 0){ // 동일 높이
                continue;
            }
            else if(h_delta_vertical[j][i] == 1){ // 상승
                if(L == 1) {
                    if(check_cline[j-1] == 0){
                        check_cline[j-1] = 1;
                        continue;
                    }
                    else{
                        possible = false;
                        cout << "impossible" << i <<"," << j << endl;
                        break;
                    }
                }
                int k = j-1;
                int cnt=0;
                while(cnt < L && k>=0){
                    if(map_info[k][i] == map_info[j][i]-1 && check_cline[k] == 0){
                        check_cline[k] = 1;
                        cnt++;
                    }
                    else break;
                    k--;
                }
                if(cnt == L){
                    continue;
                }
                else{
                    cout << "impossible" << i <<"," << j << endl;
                    possible = false; 
                    break;
                }
            }
            else if (h_delta_vertical[j][i] == -1){ // 감소"
                if(L == 1) {
                    if(check_cline[j] == 0){
                        check_cline[j] = 1;
                        continue;
                    }
                    else{
                        possible = false;
                        cout << "impossible" << i <<"," << j << endl;
                        break;
                    }
                }
                int k = j+1;
                int cnt=0;
                while(cnt < L-1 && k<N){
                    if(map_info[k][i] == map_info[j][i] && check_cline[k] == 0){
                        check_cline[k] = 1;
                        cnt++;
                    }
                    else break;
                    k++;
                }
                if(cnt == L-1)
                    // 겹치는 경사로 아니면 가능
                    continue;
                else {
                    cout << "impossible" << i <<"," << j << endl;
                    possible = false;
                    break;
                }
            }
        }
        if(possible == true){
            answer++;
        }
        // 가능한 길
    }


    cout << answer << endl;
    return 0;
}