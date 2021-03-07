#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> points(3, 0);
    int answers_len = answers.size();
    vector<int> supoja1 = {1, 2, 3, 4, 5};
    vector<int> supoja2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supoja3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int s_1 = supoja1.size(), s_2 = supoja2.size(), s_3 = supoja3.size(); // 5 8 10
    for (int i = 0; i < answers_len; i++)
    {
        int comp = answers[i];
        if(supoja1[i % s_1] == comp)
            points[0] += 1;
        if(supoja2[i % s_2] == comp)
            points[1] += 1;
        if(supoja3[i % s_3] == comp)
            points[2] += 1;
    }
    int max = points[0];
    for(int i=1;i<3;i++){
        if(points[i] > max){
            max = points[i];
        }
    }
    for(int i =0;i<3;i++)
    {
        if(points[i] == max)
            answer.push_back(i+1);
    }

    return answer;
}

int main()
{
    vector<int> answers = {1,2,3,4,5};
    vector<int> result = solution(answers);
    for(auto i : result)
    {
        cout << i << endl;
    }
    return 0;
}