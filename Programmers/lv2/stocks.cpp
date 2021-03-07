#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution1(vector<int> prices) {
    int prices_size = prices.size();
    vector<int> answer (prices_size, 0);
    for(int i=0;i<prices_size-1;i++){
        int val = 0;
        for(int j=i+1;j<prices_size;j++){
            if(prices[i] <= prices[j])
                val++;
        }
        answer[i] += val;
    }
    return answer;
}

vector<int> solution(vector<int> prices){
    int prices_size = prices.size();
    vector<int> answer;
    for(int i=prices_size-1; i>=0; i--){
        int val = 1;
        if(i == prices_size - 1){ answer.push_back(0); continue;}
        for(int j=i+1;j<prices_size;j++){
            if(prices[i] > prices[j]){
                answer.push_back(val);
                break;
            }
            if( j == prices_size - 1)
                answer.push_back(j-i);
            val++;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    vector<int> prices = {1, 2, 3, 2, 3}; //               3 4 1 2 1 0
    vector<int> result = solution(prices);
    for ( auto x : result)
        cout << x << endl;
    return 0;
}