#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/articulation-point-1/1

class Solution
{
private:
    int timer = 1;

public:
    void dfs(int node, int parent, vector<bool> &visited, vector<int> &low, vector<int> &tin,
             vector<bool> &arti, vector<int> adj[])
    {
        visited[node] = true;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto &it : adj[node])
        {
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, visited, low, tin, arti, adj);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1)
                {
                    arti[node] = true;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (parent == -1 && child > 1)
        {
            arti[node] = true;
        }
    }

    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<bool> visited(n, false);
        vector<int> low(n), tin(n);
        vector<bool> arti(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, visited, low, tin, arti, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arti[i])
            {
                ans.push_back(i);
            }
        }

        return ans.empty() ? vector<int>{-1} : ans;
    }
};
