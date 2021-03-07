/*
Related Topic : Dynamic Programming, DFS

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 

Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example
    Input: nums is [1, 1, 1, 1, 1], S is 3. 
    Output: 5
    Explanation: 
    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

    There are 5 ways to assign symbols to make the sum of nums be target 3.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void dp(vector<vector<int> >& arr, vector<int>& nums, int i, int S){
        if(i == n+1){
            return;
        }
        for(auto x : arr[i-1]){
            if(i == n){
                if(x + nums[i-1] == S)
                    arr[i].push_back(x + nums[i-1]);
                if(x - nums[i-1] == S)
                    arr[i].push_back(x - nums[i-1]);
                continue;
            }
            arr[i].push_back(x + nums[i-1]);
            arr[i].push_back(x - nums[i-1]);
        }
        dp(arr, nums, i+1, S);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        n = nums.size();
        int result = 0;
        vector<vector<int> > arr (n+1, vector<int> ());
        arr[0].push_back(0);
        dp(arr, nums, 1, S);
        result = arr[n].size();

        return result;
    }
};

int main(){

    Solution s;
    vector<int> nums = {1,1,1,1,1};
    vector<int> nums2 = {17,2,1,20,17,36,6,47,5,23,19,9,4,26,46,41,12,11,12,8};
    cout << s.findTargetSumWays(nums, 3) << endl;
    cout << s.findTargetSumWays(nums2, 26) << endl;
    return 0;
}