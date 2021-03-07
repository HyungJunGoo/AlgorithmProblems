#include<bits/stdc++.h>
using namespace std;

int main()
{
    // 1 부터 n 까지 담을 벡터
    vector<int> n;

    
    for(int i=0; i<3; i++)
        n.push_back(1);

    // 0과 1을 저장할 벡터
    vector<int> ind;

    // if k = 2
    int k = 2;
    for(int i=0; i<k; i++)
        ind.push_back(1);
    for(int i=0; i<n.size()-k; i++)
        ind.push_back(0);
    
    sort(ind.begin(), ind.end());

    do
    {
        for(int i=0; i<ind.size(); i++)
        {
            if(ind[i] == 1)
                cout << n[i] << " ";
        }
        cout << endl;
    } while (next_permutation(ind.begin(), ind.end()));
    


}