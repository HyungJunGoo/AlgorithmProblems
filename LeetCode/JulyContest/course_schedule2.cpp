/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 

which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 

return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 

If it is impossible to finish all courses, return an empty array.

Example
    Input: 2, [[1,0]] 
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
                course 0. So the correct course order is [0,1] .

    Input: 4, [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,1,2,3] or [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
                courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
                So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
*/

#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V; // number of vertices
    list<int> *adj; // a pointer to an array containing adjacency list
    vector<int> indegree; // vector to store indegree of vertices
    bool check_cycleUtil(int i, bool visited[], bool* recstack);
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void topological(vector<int>&res, bool visited[]);
    bool check_cycle();
    void show_indegree();
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    // Initializing all indegree with 0
    for(int i=0; i<V; i++)
        indegree.push_back(0);
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v's list
    indegree[w]++;
}
void Graph::show_indegree(){
    for(int i=0; i<V; i++)
        cout << indegree[i] << endl;
    return;
}
void Graph::topological(vector<int>&res, bool visited[]){
    // bool flag = false;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0 && !visited[i]){
            list<int>::iterator it;
            for(it = adj[i].begin(); it!=adj[i].end(); it++)
                indegree[*it]--;
            res.push_back(i);
            visited[i] = true;
            topological(res, visited);
            // visited[i] = false;
            // res.erase(res.end()-1);
            // for(it = adj[i].begin(); it!=adj[i].end(); it++)
            //     indegree[*it]++;
        }
    }
}
bool Graph::check_cycleUtil(int i, bool visited[], bool* recstack){
    if(!visited[i]){
        // Mark the current node as visted and part of recursion stack
        visited[i] = true; recstack[i] = true;
        // Recur all the vertices adjacent to this vertex
        list<int>::iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            if(!visited[*it] && check_cycleUtil(*it, visited, recstack))
                return true;
            else if (recstack[*it])
                return true;
        }
    }
    
    recstack[i] = false;
    return false;
}
bool Graph::check_cycle(){
    bool* visited = new bool[V];
    bool* recstack = new bool[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
        recstack[i] = false;
    }
    for(int i=0; i<V; i++){
        if(check_cycleUtil(i, visited, recstack))
            return true;
    }
    return false;
}
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        vector<int> result;
        bool visited[numCourses];
        for(int i=0; i<numCourses; i++) visited[i] = false;
        int num = prerequisites.size();
        for(int i=0; i<num; i++){
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        g.show_indegree();
            
        if(g.check_cycle()) {
            cout << "It has cycle!"<<endl; 
            return result;
        }
        g.topological(result, visited);
        cout << "-----------"<<endl;
        g.show_indegree();
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> answer;
    vector<vector<int> > prerequisites (7, vector<int> (2));
    prerequisites[0] = {5,8};
    prerequisites[1] = {3,5};
    prerequisites[2] = {1,9};
    prerequisites[3] = {4,5};
    prerequisites[4] = {0,2};
    prerequisites[5] = {7,8};
    prerequisites[6] = {4,9};
    // prerequisites[7] = {3,0};
    // prerequisites[8] = {3,0};
    // prerequisites[9] = {3,0};
    
    
    answer = s.findOrder(10, prerequisites);
    for(auto n : answer)
        cout << n << " ";
    cout << endl;
    return 0;
}