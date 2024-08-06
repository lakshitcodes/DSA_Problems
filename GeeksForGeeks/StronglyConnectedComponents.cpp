#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
private:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[node] = true;
        for (auto &i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[node] = true;
        for (auto &i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> st;
        vector<bool> visited(V, false);

        // Doing DFS and storing in stack
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }

        // Creating reverse graph
        vector<vector<int>> rAdj(V);
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            for (auto &j : adj[i])
            {
                rAdj[j].push_back(i);
            }
        }

        // Performing DFS and counting SCC
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                scc++;
                dfs(node, visited, rAdj);
            }
        }
        return scc;
    }
};