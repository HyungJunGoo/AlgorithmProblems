#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size(); //3
    vector<int> time(size,0);
    for(int i=0; i<size; i++)
    {
        int done = progresses[i];
        int speed = speeds[i];
        int todo;
        if((100 - done) % speed == 0)
            todo = (100 - done) / speed;
        else todo = ((100 - done) / speed) + 1;
        time[i] += (todo);
    }
    for(auto i: time)
        cout << i << endl;
    cout << endl;
    int release = 1;
    int next_release = time[0]; // 7
    for(int i=1;i<size;i++)
    {
        if(time[i] <= next_release) //3, 7
            release++;
        else{
            answer.push_back(release);
            release = 1;
            next_release = time[i];
        }
    }
    answer.push_back(release);
    return answer;
}

int main()
{
    vector<int> progresses = {93,30,55};
    vector<int> speeds = {1,30,5}; 
    vector<int> result = solution(progresses, speeds);

    for(auto x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}