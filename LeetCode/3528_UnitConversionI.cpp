#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/unit-conversion-i/

class Solution
{
public:
    vector<int> baseUnitConversions(vector<vector<int>> &conversions)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int mod = 1e9 + 7;
        unordered_map<int, vector<pair<int, long long>>> adj;
        for (auto &i : conversions)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        queue<pair<int, long long>> q;
        q.push({0, 1LL});
        int n = conversions.size() + 1;
        vector<int> ans(n, 1);
        vector<bool> vis(n, false);

        while (!q.empty())
        {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            if (vis[node])
            {
                continue;
            }
            vis[node] = true;
            ans[node] = cost;
            for (auto &i : adj[node])
            {
                long long newCost = cost * i.second;
                newCost %= mod;
                q.push({i.first, newCost});
            }
        }
        return ans;
    }
};