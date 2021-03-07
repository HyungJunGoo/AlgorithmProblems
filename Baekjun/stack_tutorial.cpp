#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 1;
    int N;
    cin >> N;
    vector<int> answer;
    map<string, int> functions;
    stack<int> Stack;
    functions["push"] = 0;
    functions["pop"] = 1;
    functions["size"] = 2;
    functions["empty"] = 3;
    functions["top"] = 4;

    while (cnt <= N)
    {
        string tmp;
        cin >> tmp;
        int num = functions[tmp];
        switch (num)
        {
        case 0:
            int n1;
            cin >> n1;
            Stack.push(n1);
            break;
        case 1://pop
            int n;
            if(Stack.empty()) n = -1;
            else{
                n = Stack.top();
                Stack.pop();
            }
            answer.push_back(n);
            break;
        case 2: // size
            answer.push_back(Stack.size());
            break;
        case 3: // empty
            if(Stack.empty()) answer.push_back(1);
            else answer.push_back(0);
            break;
        case 4: // top
            if(Stack.empty())
                answer.push_back(-1);
            else
                answer.push_back(Stack.top());
            break;
        default:
            break;
        }
        cnt++;
    }
    for(auto i : answer)
        cout << i << '\n';

    return 0;
}