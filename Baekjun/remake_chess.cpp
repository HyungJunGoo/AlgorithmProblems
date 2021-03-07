#include <bits/stdc++.h>
using namespace std;
int N, M;

int remake(vector<string>& board, int x, int y){ // main function to check how many changes are needed
    int answer1, answer2 = 0;
    int turn = 1;
    for(int i=x; i< x+8; i++, turn++){
        string tmp = board[i].substr(y,8);
        if(turn%2 == 1){ // 1 , 3, 5, 7
            for(int c=0; c<8; c++){
                string to_cmp1 = "WBWBWBWB";
                string to_cmp2 = "BWBWBWBW";
                if(tmp[c] != to_cmp1[c])
                    answer1++;
                if(tmp[c] != to_cmp2[c])
                    answer2++;
            }
        }
        else if(turn%2 == 0){ // 2, 4, 6, 8
            for(int c=0; c<8; c++){
                string to_cmp1 = "WBWBWBWB";
                string to_cmp2 = "BWBWBWBW";
                if(tmp[c] != to_cmp2[c])
                    answer1++;
                if(tmp[c] != to_cmp1[c])
                    answer2++;
            }
        }
    }
    if(answer1 < answer2) return answer1;
    return answer2;
}

int main()
{
    cin >> N >> M;
    vector<string> board(N);
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        board[i] = tmp;
    }
    int answer = 64;
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            int t_ans = remake(board, i, j);
            if(t_ans < answer)
                answer = t_ans;
        }
    }
    cout << answer << endl;
    return 0;
}