#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int max_stone = *max_element(stones.begin(), stones.end());
    int min_stone = *min_element(stones.begin(), stones.end());
    int mid_stone  = (max_stone + min_stone)/2;
    int cnt = 0;
    while(mid_stone>min_stone)
    {
        int cnt = 0;

        for(int i=0; i<stones.size(); i++){
            if(stones[i] < mid_stone)
                cnt += 1;
            else
                cnt = 0;
            if(cnt == k){ // cannot pass
                max_stone = mid_stone;
                mid_stone = (min_stone + max_stone)/2;
                break;
            }
        }
        if(cnt != k){
            min_stone = mid_stone;
            mid_stone = (min_stone + max_stone) / 2; 
        }
    }
    cnt = 0;
    for(int i=0; i<stones.size(); i++){
        if(stones[i] < mid_stone)
            cnt += 1;
        else
            cnt = 0;
        if (cnt == k){
            mid_stone -=1;
            break;
        }
    }
    answer = mid_stone;
    return answer;
}

int main()
{
    cout << solution({2,4,5,3,2,1,4,2,5,1}, 3) << endl;
    // cout << solution({2,4,5,4,2,1,4,2,5,1}, 3) << endl;
    // cout << solution({1,1,1,1,1,1,1,1,1,1}, 3) << endl;
    // cout << solution({5,3,6,1,1,2}, 3) << endl;
    return 0;
}