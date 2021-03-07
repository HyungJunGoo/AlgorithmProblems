/*
Given a non-empty array of integers, return the k most frequent elements.
Example
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Input: nums = [1], k = 1
    Output: [1]
*/
#include <bits/stdc++.h>
using namespace std;

bool mysort(pair<int, int> &a, pair<int, int> &b){
    return a.second> b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq_list; // number, frequent
        vector<pair<int, int> > f_list;
        vector<int> result;
        for(auto i : nums){
            if(!freq_list[i]) freq_list[i] = 1;
            else freq_list[i] += 1;
        }
        map<int, int>::iterator it;
        for(it = freq_list.begin(); it != freq_list.end(); it++){
            f_list.push_back(make_pair((*it).first, (*it).second));
        }
        sort(f_list.begin(), f_list.end(), mysort);
        for(int i=0; i<k; i++){
            result.push_back(f_list[i].first);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1};
    vector<int> answer = s.topKFrequent(nums, 1);
    for(auto i : answer)
        cout << i << " ";
    cout << endl;
    return 0;
}