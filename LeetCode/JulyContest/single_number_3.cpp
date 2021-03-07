/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 

Find the two elements that appear only once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> count_nums;
    vector<int> singleNumber(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(!count_nums[nums[i]]){
                count_nums[nums[i]] = 1;
            }
            else
                count_nums[nums[i]]++;
        }
        map<int, int>::iterator itr;
        vector<int> result;
        for(itr = count_nums.begin(); itr != count_nums.end(); itr++){
            if((*itr).second == 1)
                result.push_back((*itr).first);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,1,3,2,5};
    Solution s;
    vector<int> answer = s.singleNumber(nums);
    for(auto n : answer)
        cout << n << endl;
    return 0;
}