#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int first = 1;
    int last = *max_element(stones.begin(), stones.end());
    int mid = (first + last)/2;

    return answer;
}


int main()
{
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout <<solution(stones, k) << endl;
    return 0;
}