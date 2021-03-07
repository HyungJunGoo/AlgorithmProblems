#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int N, int remain, int K, int num, vector<int>& result){
        if(remain == 0){
            result.push_back(num);
            return;
        }
        string tmp = to_string(num);
        int bit = tmp[tmp.length()-1] - '0';
        if(bit-K >= 0 ){
            string tmp_l = tmp + to_string(bit-K);
            DFS(N, remain-1, K, stoi(tmp_l), result);
        }
        if(K != 0 && bit+K <= 9){
            string tmp_r = tmp + to_string(bit+K);
            DFS(N, remain-1, K, stoi(tmp_r), result);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if(N==1){
            for(int i=0; i<=9; i++)
                result.push_back(i);
            return result;
        }
        for(int i=1; i<=9; i++)
            DFS(N, N-1, K, i, result);

        return result;
    }
};

int main()
{  
    int N, K;
    N = 3;
    K = 3;
    Solution s;
    vector<int> answer = s.numsSameConsecDiff(N,K);
    for(auto n : answer)
        cout << n << " ";
    cout << endl;

    return 0;
}