#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l_divisor = 1;
        int r_divisor = 1e6;

        while (l_divisor < r_divisor)
        {
            int sum = 0;
            int m_divisor = (l_divisor + r_divisor) / 2;
            for (int i : nums)
            {
                sum += ceil(float(i) / float(m_divisor));
            }
            if (sum <= threshold)
            {
                r_divisor = m_divisor;
            }
            else
            {
                l_divisor = m_divisor + 1;
            }
        }

        return l_divisor;
    }
};

int main()
{
    Solution solution;
}