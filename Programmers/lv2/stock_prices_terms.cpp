#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    int min_val = prices[n-1];
    int min_idx = n-1;
    answer.push_back(0);
    
    for (int i = n-2; i >= 0; i--)
    {
        if(prices[i] > min_val){
            int l = min_idx - i;
            answer.push_back(l);
        }
        else{
            int l = n - i - 1;
            answer.push_back(l);
            if (prices[i] < min_val){
                min_val = prices[i];
                min_idx = i;
            }
        }
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> result = solution({1,2,3,2,3});
    for (int n : result){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}