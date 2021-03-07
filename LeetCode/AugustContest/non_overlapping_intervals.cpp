/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make 
the rest of the intervals non-overlapping.

Example 1:

    Input: [[1,2],[2,3],[3,4],[1,3]]
    Output: 1
    Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Example 2:

    Input: [[1,2],[1,2],[1,2]]
    Output: 2
    Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Example 3:

    Input: [[1,2],[2,3]]
    Output: 0
    Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/


#include <bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a, const vector<int>&b){
    if(a[1] == b[1])return a[0] > b[0];
    else return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int prevEnd = INT32_MIN;
        int minErase = 0;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            vector<int> tmp = intervals[i];
            if(prevEnd > tmp[0]) minErase++;
            else prevEnd = tmp[1];
        }
        return minErase;
    }
};

int main()
{
    vector<vector<int>> intervals = { {1,2}, {2,3}, {3,4}, {1,3}};
    vector<vector<int>> intervals2 = { {1,2}, {1,2},{1,2}};
    Solution s;
    cout << s.eraseOverlapIntervals(intervals2) << endl;
    return 0;
}