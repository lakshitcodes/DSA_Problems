#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/

class Solution
{
public:
    int maxDepth = 0;
    void dfs(int node, int parent, int depth, vector<vector<int>> &adj)
    {
        maxDepth = max(maxDepth, depth);
        for (auto &x : adj[node])
        {
            if (parent != x)
            {
                dfs(x, node, depth + 1, adj);
            }
        }
    }
    long long power(long long x, long long y, long long mod)
    {
        long long result = 1;
        while (y > 0)
        {
            if (y % 2)
            {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            y /= 2;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> adj(edges.size() + 2);
        for (auto &i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        maxDepth = 0;
        dfs(1, -1, 0, adj);
        return power(2, maxDepth - 1, 1e9 + 7);
    }
};