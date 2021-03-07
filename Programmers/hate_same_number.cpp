#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = -1;
    int num = arr.size();
    for(int i=0; i<num; i++){
        if(prev < 0){
            prev = arr[i];
            continue;
        }
        if(arr[i] == prev)
            continue;
        else if (arr[i] != prev){
            answer.push_back(prev);
            prev = arr[i];
        }
    }
    answer.push_back(prev);
    return answer;
}

int main()
{
    vector<int> ans;
    ans = solution({1,1,3,3,0,1,1});
    for(auto a : ans)
        cout << a << endl;
    ans = solution({4,4,4,3,3});
    for(auto a : ans)
        cout << a << endl;
    return 0;
}