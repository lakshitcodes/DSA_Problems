#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution
{
public:
    class compartor
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> ans(N, INT_MAX);
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compartor> pq;
        pq.push({src, 0});

        while (!pq.empty())
        {
            auto frontElement = pq.top();
            pq.pop();
            if (ans[frontElement.first] > frontElement.second)
            {
                for (auto &i : adj[frontElement.first])
                {
                    pq.push({i, frontElement.second + 1});
                }
                ans[frontElement.first] = frontElement.second;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (ans[i] == INT_MAX)
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};