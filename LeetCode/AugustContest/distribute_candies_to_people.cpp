#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res (num_people, 0);
        int c = 1;
        int order =0;
        while(candies > 0){
            if(order == num_people) order -= num_people;
            if(candies >= c)
                res[order] += c;
            else
                res[order] += candies;
            candies -= c;
            c++;
            order++;
        }

        return res;
    }
};

int main()
{
    int candies = 7;
    int num_people = 4;
    Solution s;
    vector<int> ans = s.distributeCandies(candies, num_people);
    for(int n : ans)
        cout << n << " ";
    cout << endl;

    return 0;
}