/*
    Input: nums = [1,2,3]
    Output:
    [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
    ]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void push(vector<int>& nums, vector<vector<int> >& result, int n, int r){
        if(n==r) {
            result.push_back(nums);
            return;
        }
        vector<bool> v(n);
        fill(v.end()-r, v.end(), true);
        do
        {
            vector<int> tmp;
            for(int i=0; i<n; i++){
                if(v[i])
                    tmp.push_back(nums[i]);
            }
            result.push_back(tmp);
        } while (next_permutation(v.begin(), v.end()));
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size(); // total number of elements
        vector<vector<int> > result;
        vector<int> none = {};
        result.push_back(none);
        for(int i = size; i>=1; i--)
            push(nums, result, size, i);

        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,10,0};
    Solution s;
    vector<vector<int> > answer = s.subsets(nums);
    for(auto v : answer){
        for(auto n : v){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}