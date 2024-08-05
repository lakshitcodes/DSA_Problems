#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/critical-connections-in-a-network/

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<bool> &visited, vector<int> adj[],
             vector<int> &low, vector<int> &tin, vector<vector<int>> &bridges)
    {
        visited[node] = true;
        low[node] = tin[node] = timer;
        timer++;
        for (auto i : adj[node])
        {
            if (i == parent)
                continue;
            if (!visited[i])
            {
                dfs(i, node, visited, adj, low, tin, bridges);
                low[node] = min(low[node], low[i]);
                // checking if it is a bridge
                if (tin[node] < low[i])
                {
                    bridges.push_back({node, i});
                }
            }
            else
            {
                low[node] = min(low[node], low[i]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> adj[n];
        for (auto &i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        vector<int> low(n), tin(n);
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, low, tin, bridges);

        return bridges;
    }
};