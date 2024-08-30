#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/modify-graph-edge-weights/

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    const int INF = 2e9;

    int dijkstraAlgo(int n, int source, int destination)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (!visited[curr])
            {
                visited[curr] = true;
                for (auto &neighbor : adj[curr])
                {
                    if (dist[neighbor.first] > weight + neighbor.second)
                    {
                        dist[neighbor.first] = weight + neighbor.second;
                        pq.push({dist[neighbor.first], neighbor.first});
                    }
                }
            }
        }
        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Create the initial graph
        for (auto &i : edges)
        {
            if (i[2] != -1)
            {
                adj[i[0]].push_back({i[1], i[2]});
                adj[i[1]].push_back({i[0], i[2]});
            }
        }

        int currShortestDist = dijkstraAlgo(n, source, destination);
        if (currShortestDist < target)
        {
            return {}; // Impossible
        }

        bool match = (currShortestDist == target);

        for (auto &i : edges)
        {
            if (i[2] != -1)
            {
                continue;
            }
            i[2] = match ? INF : 1;
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});

            if (!match)
            {
                int distance = dijkstraAlgo(n, source, destination);
                if (distance <= target)
                {
                    match = true;
                    i[2] += target - distance;
                    adj[i[0]].back().second = i[2];
                    adj[i[1]].back().second = i[2];
                }
            }
        }

        if (match)
            return edges;
        return {};
    }
};
