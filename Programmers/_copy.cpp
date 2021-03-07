#include <string>
#include <vector>
using namespace std;
bool visited[1<<8];

bool isPossible(string a, string b)
{
    if(a.size()!=b.size()) return false;
    int a_size = a.size();
    for(int i = 0 ; i <a_size; i++)
    {
        if(!(a[i]==b[i] || a[i] == '*' || b[i] == '*')) return false;
    }
    return true;
}

void dfs(int bannedIdx, int N, int bits, const vector<vector<int>>&v)
{
    if(bannedIdx == N)
    {
        visited[bits] = true;
        return;
    }
    for(auto next:v[bannedIdx])
    {
        if(bits&(1<<next)) continue;
        dfs(bannedIdx+1, N, bits|(1<<next), v);
    }
}

int solution(vector<string> user_id, vector<string> banned_id){
    int answer = 0;
    int banned_id_size = banned_id.size();
    int user_id_size = user_id.size();
    vector<vector<int>>v(banned_id_size);
    for (int i = 0; i < banned_id_size; i++)
    {
        string banned = banned_id[i];
        for(int j=0; j<user_id_size; j++)
        {
            string user = user_id[j];
            if(isPossible(banned, user))
                v[i].push_back(j);
        }
    }
    dfs(0, banned_id_size, 0, v);
}