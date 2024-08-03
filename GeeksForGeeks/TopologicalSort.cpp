#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/topological-sort/1

// DFS
class Solution
{
private:
    void dfs(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[])
    {
        visited[node] = true;
        for (auto &i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// BFS - Kahn's Algorithm
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        vector<bool> visited(V, false);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto &j : adj[i])
            {
                inDegree[j]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (!visited[front])
            {
                visited[front] = true;
                ans.push_back(front);
                for (auto &i : adj[front])
                {
                    if (!visited[i] && --inDegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};