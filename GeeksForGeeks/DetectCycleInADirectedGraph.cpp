#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto &j : adj[i])
            {
                inDegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<bool> visited(V, false);
        vector<int> topo;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (!visited[front])
            {
                visited[front] = true;
                topo.push_back(front);
                for (auto &i : adj[front])
                {
                    if (!visited[i] && --inDegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return topo.size() != V;
    }
};