#include <bits/stdc++.h>
using namespace std;

bool comp(string &a, string &b){
    if(a.size() != b.size()) return false;
    bool result = false;
    int len = a.size();
    for(int i = 0; i < len; i++){
        if(b[i] == '*') continue;
        else if(a[i] != b[i]) return false;
    }
    result = true; return result;
}

void dfs(int bannedidx, int N, vector<vector<int> > candidate, string bits, vector<int> &visited)
{
    cout << "visited size : " << visited.size() << endl;
    cout << bits << endl;
    if (bits.size() == N){
        sort(bits.begin(), bits.end());
        int to_put = stoi(bits);
        cout << "to_put : " << to_put << endl;
        if(visited[to_put] == 0)
            visited[to_put] += to_put;
        cout << "put into visited[ "<< to_put<< "] " << visited[to_put] << endl;
        return;
    } // If bits size is equal to length of banned_id ,it is eligible to check whether it could be in visited or not.
    
    for(auto i : candidate[bannedidx])
    {
        if( bits.find(to_string(i)) != string::npos)
            continue; // If found
        string temp_bits = bits;
        dfs(bannedidx+1, N, candidate, temp_bits+= to_string(i) , visited);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int len_banned_id = banned_id.size(); //4
    int len_user_id = user_id.size();
    static vector<int> visited(pow(10,len_user_id), 0);
    cout << "visited size: " << visited.size() << endl;
    vector<vector<int> > candidate (len_banned_id);
    for(int i = 0; i < len_banned_id; i++)
    {
        vector<int> temp_candidate;
        for (int j = 0; j<len_user_id; j++)
        {
            if(comp(user_id[j], banned_id[i]) == true)
                temp_candidate.push_back(j+1); // for comfort (j+1)
        }
        candidate[i] = temp_candidate;
    }

    dfs(0,len_banned_id, candidate, "", visited);
    for (auto i : visited)
    {
        // cout << i << endl;
        if(i != 0)
            answer++;
    }
    
    return answer;
}

int main()
{
    vector<string> user_id  {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id  {"fr*d*", "*rodo", "******", "******"};
    
    int result = solution(user_id, banned_id);
    cout << result << endl;
    return 0;
}