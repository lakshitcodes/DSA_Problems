#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n, 0);

        for (auto &i : edges)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));

        int visited = 0;
        int ans = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            visited++;

            int colorIdx = colors[node] - 'a';
            dp[node][colorIdx]++;

            ans = max(ans, dp[node][colorIdx]);
            for (auto &i : adj[node])
            {
                for (int c = 0; c < 26; c++)
                {
                    dp[i][c] = max(dp[i][c], dp[node][c]);
                }
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return (visited == n) ? ans : -1;
    }
};