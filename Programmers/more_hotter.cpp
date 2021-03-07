/*
매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다.
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.

섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    if(*scoville.begin() >= K)
        return answer;
    while (*scoville.begin() < K)
    {
        int n = scoville[0] + (scoville[1]*2);
        scoville[0] = n;
        answer++;
        scoville.erase(scoville.begin()+1);
        if(scoville.size() == 1) break;
        sort(scoville.begin(), scoville.end());
    }
    if(*scoville.begin() < K)   return -1;
    return answer;
}
int solution2(vector<int> scoville, int K) {
    int answer = 0;
    map<int, int> heap;
    int size = scoville.size();
    for(int i=0; i < size; i++)
        heap[scoville[i]] = 1;
    if((*heap.begin()).first >= K)
        return answer;
    while ( (*heap.begin()).first < K )
    {
        int first = (*heap.begin()).first;
        heap.erase(heap.find(first));
        int second = (*heap.begin()).first;
        heap.erase(heap.find(second));
        int n = first + (second*2);
        heap[n] = 1;
        answer++;
        if(heap.size() == 1)break;
        if((*heap.begin()).first >= K) return answer;
    }
    
    if((*heap.begin()).first < K) return -1;
    return answer;
}

int solution3(vector<int> scoville, int K){
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto s : scoville)
        min_heap.push(s);
    while (min_heap.top() < K)
    {
        if(min_heap.size() == 1)
            break;
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();
        int n = first + (second*2);
        min_heap.push(n);
        answer++;
    }
    if(min_heap.top() < K) return -1;

    return answer;
}
int main()
{
    cout << solution3({1, 2, 3, 9, 10, 12}, 7) << endl; //2
    return 0;
}