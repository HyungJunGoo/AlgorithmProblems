#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0; int high = nums.size()-1;
        while(lo < high) {
           int mid = lo + (high - lo) / 2;
           if(nums[mid] > nums[high])   
                lo = mid + 1;
            else if (nums[mid] < nums[high])
                high = mid;
            else
                high--;
       }
        return nums[lo];
    }
};

int main()
{
    vector<int> nums = {1,1,1,1,0,1,1};
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}