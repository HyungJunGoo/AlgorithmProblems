#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {

        unordered_map<int, int> countPosition;
        countPosition.clear();
        for (int i = 0; i < position.size(); i++)
            if (!countPosition[position[i]])
                countPosition[position[i]] = 1;
            else
                countPosition[position[i]]++;

        int even = 0, odd = 0;
        for (auto cnt : countPosition)
        {
            if (cnt.first % 2 == 0)
                even += cnt.second;
            else
                odd += cnt.second;
        }
        return min(even, odd);
    }
};