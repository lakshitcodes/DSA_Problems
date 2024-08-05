#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &i : roads)
        {
            int u = i[0], v = i[1], cost = i[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        const long long mod = 1e9 + 7;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto front = pq.top();
            long long distance = front.first;
            long long node = front.second;
            pq.pop();

            for (auto &i : adj[node])
            {
                long long nc = distance + i.second;
                long long element = i.first;
                if (dist[element] > nc)
                {
                    dist[element] = nc;
                    pq.push({nc, element});
                    ways[element] = ways[node];
                }
                else if (dist[element] == nc)
                {
                    ways[element] += ways[node];
                    ways[element] %= mod;
                }
            }
        }
        return ways[n - 1];
    }
};