#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> _arr1;
    vector<string> _arr2;

    for(int i=0;i<n;i++){
        string temp = "";
        while (arr1[i] > 1)
        {
            if(arr1[i] % 2 == 1)
                temp += "1";
            else
                temp += "0";
            arr1[i] /=2;
        }
        if(arr1[i] == 0) temp+="0";
        else temp += "1";
        reverse(temp.begin(), temp.end());
        while(temp.length() <n){
            temp.insert(0, "0");
        }
        _arr1.push_back(temp);
        cout<< temp << endl;
    }
    for(int i=0;i<n;i++){
        string temp = "";
        while (arr2[i] > 1)
        {
            if(arr2[i] % 2 == 1)
                temp += "1";
            else
                temp += "0";
            arr2[i] /=2;
        }
        if(arr2[i] == 0) temp+="0";
        else temp += "1";
        reverse(temp.begin(), temp.end());
        while(temp.length() <n){
            temp.insert(0, "0");
        }
        _arr2.push_back(temp);
        cout<< temp << endl;
    }
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for(int j = 0; j < n; j++){
            if(_arr1[i][j] == '1' || _arr2[i][j] == '1')
                temp += "#";
            else
                temp += " ";
        }
        answer.push_back(temp);
    }
    cout << endl;

    return answer;
}

int main()
{
    int n = 5;
    vector<int> arr1 = {0, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    vector<string> result = solution(n, arr1, arr2);
    
    for(int i=0;i<n;i++){
        cout << result[i] << endl;
    }
    return 0;
}