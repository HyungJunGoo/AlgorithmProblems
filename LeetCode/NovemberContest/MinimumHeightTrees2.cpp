#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> result;
        vector<int> degrees(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }

        queue<int> queue;
        for (int i = 0; i < n; i++)
        {
            // adding all leave nodes
            if (degrees[i] == 1)
                queue.push(i);
        }
        while (!queue.empty())
        {
            result.clear();
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                int current = queue.front();
                queue.pop();
                result.push_back(current); // adding nodes to vector. Goal is to get a vector of 1 or 2 nodes availabel

                for (auto &neighbor : adj[current])
                {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1)
                        queue.push(neighbor);
                }
            }
        }
        return result;
    }
};
