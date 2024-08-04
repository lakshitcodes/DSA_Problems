#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/network-delay-time/description/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &i : times)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty())
        {
            pair<int, int> front = pq.top();
            int cost = front.first;
            int node = front.second;
            pq.pop();
            for (auto &i : adj[node])
            {
                if (dist[i.first] > cost + i.second)
                {
                    dist[i.first] = cost + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        int maxi = *max_element(dist.begin() + 1, dist.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};