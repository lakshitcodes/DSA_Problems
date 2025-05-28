#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/

class Solution
{
public:
    int dfs(vector<vector<int>> &adj, int u, int p, int k)
    {
        if (k < 0)
        {
            return 0;
        }
        int count = 1;
        for (auto v : adj[u])
        {
            if (v != p)
            {
                count += dfs(adj, v, u, k - 1);
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);
        for (auto &e : edges1)
        {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            maxi = max(dfs(adj2, i, -1, k - 1), maxi);
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = dfs(adj1, i, -1, k) + maxi;
        }

        return ans;
    }
};