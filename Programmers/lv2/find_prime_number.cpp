#include<bits/stdc++.h>
using namespace std;

bool check_prime_number(int tmp_n){
    if (tmp_n == 1 || tmp_n == 4) return false;
    if (tmp_n == 2 || tmp_n == 3) return true;
    for (int i = (tmp_n-1)/2; i>1; i--){
        if (tmp_n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    for (int i = 2; i < 20; i++)
    {
        if (check_prime_number(i))
            cout << i << endl;
    }
    return 0;
}


int solution(vector<int> nums) {
    int answer = 0;

    int n = nums.size();
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                int tmp_n = nums[i] + nums[j] + nums[k];
                if (check_prime_number(tmp_n))
                    answer++;
            }
            
        }
        
    }
    
    

    return answer;
}