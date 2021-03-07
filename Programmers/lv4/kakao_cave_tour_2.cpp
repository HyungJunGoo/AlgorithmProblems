#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>* adj;

    public:
        Graph(int V);
        list<int>* adj_list();
        void addEdge(int v, int w);
        void addPreEdge(int v, int w); // child, parent
        void DFS(int v, int w, Graph directed_g);
        bool checkCycle(int v, vector<int>& visited, vector<int>& check_list);
};


Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

list<int>* Graph::adj_list(){
    return this->adj;
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::addPreEdge(int v, int w){
    adj[w].push_back(v);
}

void Graph::DFS(int v, int w, Graph directed_g){

    directed_g.addPreEdge(v, w);
    for (int next : adj[w]){
        if (next != v){
            DFS(w, next, directed_g);
        }
    }
}

bool Graph::checkCycle(int v, vector<int>& visited, vector<int>& check_list){
    check_list[v] = 1;
    visited[v] = 1;

    for (auto next : adj[v]){
        if(next == 0) continue;
        if(check_list[next] == 0){
            if(checkCycle(next, visited, check_list) == true)
                return true;
        }
        if(visited[next] == 1)
            return true;
    }
    visited[v] = 0;
    return false;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for (auto ord: order){
        if(ord[1] == 0)
            return false;
    }
    Graph undirected_g (n);
    for (auto p : path){
        undirected_g.addEdge(p[0], p[1]);
    }
    Graph directed_g (n);
    list<int>* undirected_g_adj = undirected_g.adj_list();
    list<int>* directed_g_adj = directed_g.adj_list();
    
    stack<int> dfsstack;

    dfsstack.push(0);
    vector<int> dfsvisit(n);
    fill(dfsvisit.begin(), dfsvisit.end(), 0);
    while (!dfsstack.empty())
    {
        int top = dfsstack.top();
        dfsstack.pop();
        dfsvisit[top] = 1;
        for(int next : undirected_g_adj[top]){
            if (dfsvisit[next] == 1) continue;
            directed_g.addPreEdge(top, next);
            dfsstack.push(next);
        }
    }
    
    for (auto ord: order)
        directed_g.addPreEdge(ord[0], ord[1]);

    vector<int> check_list (n);
    fill(check_list.begin(), check_list.end(), 0);
    for(int i=1; i<n; i++){
        if (check_list[i] == 0){
            vector<int> visited(n);
            fill(visited.begin(), visited.end(), 0);
            if(directed_g.checkCycle(i, visited, check_list) == true){
                answer = false;
                break;
            }
        }
    }
    return answer;
}
int main()
{
    bool answer = solution(9 , {{0,1}, {0,3}, {0,7}, {8,1}, {3,6}, {1,2}, {4,7}, {7,5}}, {{8,5},{6,7},{4,1}});
    // bool answer2 = solution(9, {{8,1}, {0,1}, {1,2}, {0,7}, {4,7}, {0,3}, {7,5}, {3,6}}, {{4,1},{5,2}});
    bool answer3 = solution(9, {{0,1}, {0,3}, {0,7}, {8,1}, {3,6}, {1,2}, {4,7}, {7,5}}, {{4,1},{8,7},{6,5}});
    if( answer)
        cout << "answer is true" << endl;
    else
        cout << "false" << endl;
    // if( answer2)
    //     cout << "answer 2 is true" << endl;
    if( answer3)
        cout << "answer 3 is true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
