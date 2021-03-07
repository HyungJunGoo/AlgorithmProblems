#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int len = array.size(); // 7
    for(auto v : commands){
        vector<int> temp = array;
        int start, end, k;
        for(int i = 0 ; i<3; i++){
            if(i==0)
                start = v[i];
            else if(i == 1)
                end = v[i];
            else
                k = v[i];
        }
        temp.erase(temp.begin()+ 0,temp.begin() + start-1);
        temp.erase(temp.begin()+end-(start-1), temp.begin()+len-(start-1));
        sort(temp.begin(), temp.end());
        answer.push_back(temp.at(k-1));
    }
    return answer;
}

int main()
{
    vector<int> result = solution({1, 5, 2, 6, 3, 7, 4}, {{2,5,3},{4,4,1},{1,7,3}});
    for(auto i : result)
        cout << i << endl;
    return 0;
}   