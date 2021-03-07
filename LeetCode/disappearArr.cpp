#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int max = *(nums.end()-1);
    int current=1;
    for(int i=0; i<size; i++){
        if(nums[i] == current){
            current++;
            continue;
        }
        else if(nums[i] > current){
            for(int j = current; j<nums[i];j++)
                result.push_back(j);
            current = nums[i]+1;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> nums2 = {1,2,6};
    vector<int> nums3 = {1,1};
    vector<int> result = findDisappearedNumbers(nums3);
    for(auto x : result)
        cout << x << endl;

    return 0;
}