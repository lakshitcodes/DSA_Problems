#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-the-number-of-good-nodes/

class Solution
{
public:
    int dfs(int node, const vector<vector<int>> &adj, vector<int> &subtreeSize, vector<bool> &visited, vector<int> &parent)
    {
        visited[node] = true;
        int size = 1;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                parent[neighbor] = node;
                size += dfs(neighbor, adj, subtreeSize, visited, parent);
            }
        }
        subtreeSize[node] = size;
        return size;
    }

    int countGoodNodes(const vector<vector<int>> &adj, const vector<int> &subtreeSize, const vector<int> &parent)
    {
        int goodNodes = 0;
        for (int node = 0; node < adj.size(); ++node)
        {
            if (adj[node].size() == 1 && subtreeSize[node] == 1)
            {
                ++goodNodes;
                continue;
            }
            unordered_set<int> sizes;
            for (int child : adj[node])
            {
                if (child != parent[node] && subtreeSize[child] > 0)
                {
                    sizes.insert(subtreeSize[child]);
                }
            }
            if (sizes.size() == 1)
            {
                ++goodNodes;
            }
        }
        return goodNodes;
    }
    int countGoodNodes(vector<vector<int>> &edges)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> subtreeSize(n);
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        dfs(0, adj, subtreeSize, visited, parent);

        return countGoodNodes(adj, subtreeSize, parent);
    }
};
