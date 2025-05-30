#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution
{
public:
    vector<int> dijkstra(int node, vector<int> &adj)
    {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, node});
        while (!pq.empty())
        {
            int ele = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (visited[ele])
            {
                continue;
            }
            visited[ele] = true;
            dist[ele] = cost;
            if (adj[ele] != -1)
            {
                pq.push({1 + cost, adj[ele]});
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = edges.size();

        vector<int> dist1 = dijkstra(node1, edges);
        vector<int> dist2 = dijkstra(node2, edges);
        int ans = INT_MAX;
        int node = -1;

        for (int i = 0; i < n; i++)
        {
            cout << dist1[i] << " " << dist2[i] << endl;
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX)
            {
                int curr = max(dist1[i], dist2[i]);
                if (curr < ans)
                {
                    node = i;
                    ans = curr;
                }
            }
        }
        return node;
    }
};