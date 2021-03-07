/*
Given a directed, acyclic graph of N nodes.  

Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  

the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example :
Example:
    Input: [[1,2], [3], [3], []] 
    Output: [[0,1,3],[0,2,3]] 
    Explanation: The graph looks like this:
    0--->1
    |    |
    v    v
    2--->3
    There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<deque<int>> result;
    int last;
    void traverse(vector<vector<int>>& graph, deque<int>& tmp, int idx){
        if( *(tmp.end()-1) == last) {
            result.push_back(tmp);
            return;
        }
        if(graph[idx].size() ==0 )return;
        for(int i=0; i<graph[idx].size(); i++){
            tmp.push_back(graph[idx][i]);
            traverse(graph, tmp, graph[idx][i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int num = graph.size();
        last = num-1;
        int linked_num = graph[0].size();
        deque<int> tmp;
        tmp.push_back(0);
        for(int j=0; j<linked_num; j++){
            tmp.push_back(graph[0][j]);
            traverse(graph, tmp, graph[0][j]);
            tmp.pop_back();
        }
        vector<vector<int> > answer;
        for(auto d : result){
            vector<int> t;
            for(auto n : d)
                t.push_back(n);
            answer.push_back(t);
        }
        return answer;
    }   
};

int main()
{
    vector<vector<int> > graph = {{1,2}, {3}, {3}, {}};
    vector<vector<int> > graph2 = {{1,3,4}, {2,3,4}, {3}, {4}, {}};
    Solution s;
    vector<vector<int> > answer = s.allPathsSourceTarget(graph2);

    for( auto i : answer){
        for( auto x : i)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}   