#include <bits/stdc++.h>

using namespace std;

bool my_sort(int n1, int n2){

    string str1 = to_string(n1);
    string str2 = to_string(n2);

    int iter_length = min(str1.length(), str2.length());

    for (int i = 0; i < iter_length; i++)
    {
        if(str1[i] > str2[i])
            return true;
        else if (str1[i] < str2[i])
            return false;
        else{
            if ((str1.length() > iter_length) && (str2.length > iter_length))
                continue;
            else{
                if (str1.length() == iter_length)
                    return false;
                else 
                    return true;
            }
        }
    }
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), my_sort);
    vector<string> str_numbers;
    for(int number : numbers){
        str_numbers.push_back(to_string(number));
    }
    for(string str : str_numbers)
        answer += str;
    return answer;
}

int main(){
    vector<int> numbers = {8, 12, 9, 149};
    

    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    return 0;
}