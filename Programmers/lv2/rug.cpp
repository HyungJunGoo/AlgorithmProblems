#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int size = brown + yellow;
    for (int i = 3; i < size; i++)
    {
        if (size % i != 0)
            continue;
        if (i < size / i)
            continue;
        if (size / i < 3)
            continue;
        int len = (i + size / i) * 2 - 4;
        if (len == brown)
        {
            answer.push_back(i);
            answer.push_back(size / i);
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> result;
    result = solution(8, 1);
    for (int n : result)
        cout << n << " ";
    cout << endl;

    return 0;
}