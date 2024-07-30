#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Using BFS
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfsCycle(i, adj, visited, parent))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool bfsCycle(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int frontElement = q.front();
            q.pop();
            for (auto &i : adj[frontElement])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = frontElement;
                }
                else if (i != parent[frontElement])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Using DFS
class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (dfsCheckCycle(i, adj, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfsCheckCycle(int node, vector<int> adj[], vector<bool> &visited, int parent)
    {
        visited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfsCheckCycle(neighbor, adj, visited, node))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {

                return true;
            }
        }
        return false;
    }
};
