/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 

some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> check;
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int s = nums.size();
        for(int i=0; i<s; i++){
            if(!check[nums[i]])
                check[nums[i]] = 1;
            else
                check[nums[i]] ++;
        }
        unordered_map<int, int>::iterator itr;
        for(itr = check.begin(); itr != check.end(); itr++){
            if((*itr).second >=2)
                result.push_back((*itr).first);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> ans = s.findDuplicates(nums);
    for(auto n : ans)
        cout << n << " ";
    cout << endl;

    return 0;
}