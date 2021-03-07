#include <bits/stdc++.h>

using namespace std;


class Graph{
    int V;
    list<int>* adj;
    public:
        Graph(int V);
        list<int>* adj_list();
        void addEdge(int v, int w);
        void traverse(int v, int w, set<int>& visited, vector<vector<int> > order);
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

void Graph::traverse(int v, int w, set<int> &visited, vector<vector<int> > order){
    // cout << w << " ";
    vector<int> next_candidate;
    next_candidate.clear();
    visited.insert(w);
    for(auto l : adj[w]){
        if (l != v )
            next_candidate.push_back(l);
    }
    
    if(next_candidate.size() == 0){
        // cout << "    remove    " << w << " & "<< v << "   ";
        adj[w].remove(v);
        adj[v].remove(w);
        return;
        traverse(w, v, visited, order);
    }
    for (auto next : next_candidate){
        
        bool in_order = false;
        int condition = -1;
        for (auto ord : order){
            if(ord[1] == next){
                // cout << next << "is in order pair " << " ";
                in_order = true;                
                condition = ord[0];
            }
            
        }
        if(in_order == true){
            if(visited.find(condition) != visited.end()){
                traverse(w, next, visited, order);
            }
        }
        else{
            traverse(w, next, visited, order);
        }
    }
    return;
}


bool solution(int n, vector<vector<int> > path, vector<vector<int> > order) {
    bool answer = false;
    Graph graph(n);

    for(auto p : path){
        graph.addEdge(p[0], p[1]);
    }
    
    set<int> visited;
    visited.insert(0);
    int start = 0;
    
    list<int>* adj_list = graph.adj_list();

    // for (int i=0; i<n; i++) {
    //     for (auto l : adj_list[i])
    //         cout << l << " ";
    //     cout << endl;
    // }

    vector<int> candidate ;
    for (auto l : adj_list[0])
        candidate.push_back(l);
    
    while (candidate.size() != 0){
        // for( auto l : candidate)
        //     cout << l << " ";
        vector<int> new_candidate;
        new_candidate.clear();

        for (auto l : candidate){
            
            bool in_order = false;
            int condition = -1;
            for (auto ord : order){
                
                if(ord[1] == l){
                    // cout << l << "is in order pair " << " ";
                    in_order = true;                
                    condition = ord[0];
                }
            }
            if(in_order == true){
                if(visited.find(condition) != visited.end()){
                    graph.traverse(start, l, visited, order);
                    // cout << "return to home " << " ";
                    if(adj_list[l].size() != 1)
                        new_candidate.push_back(l);
                }
                else
                    new_candidate.push_back(l);
            }
            else{
                graph.traverse(start, l, visited, order);
                // cout << "return to home " << " ";
                if(adj_list[l].size() == 1){
                }
                else{
                    new_candidate.push_back(l);
                }
                    
            }
        }
        // cout << "&&&&&& reset candidate &&&&&&& " << " ";
        if(candidate.size() == new_candidate.size())
            break;
        candidate = new_candidate;
    }
    if (visited.size() == n)
        answer = true;
    // for(auto visit : visited)
    //     cout << visit << " ";
    // cout << endl;
    

    return answer;
}

int main()
{
    bool answer = solution(9 , {{0,1}, {0,3}, {0,7}, {8,1}, {3,6}, {1,2}, {4,7}, {7,5}}, {{8,5},{6,7},{4,1}});
    bool answer2 = solution(9, {{8,1}, {0,1}, {1,2}, {0,7}, {4,7}, {0,3}, {7,5}, {3,6}}, {{4,1},{5,2}});
    bool answer3 = solution(9, {{0,1}, {0,3}, {0,7}, {8,1}, {3,6}, {1,2}, {4,7}, {7,5}}, {{4,1},{8,7},{6,5}});
    if( answer)
        cout << "answer 1 is true" << endl;
    if( answer2)
        cout << "answer 2 is true" << endl;
    if( answer3)
        cout << "answer 3 is true" << endl;
    return 0;
}