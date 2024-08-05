#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Kruskal
class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> rank, parent;
        DisjointSet(int n)
        {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int i)
        {
            if (parent[i] == i)
            {
                return i;
            }
            int rr = findParent(parent[i]);
            parent[i] = rr;
            return rr;
        }
        void unite(int a, int b)
        {
            int r1 = findParent(a);
            int r2 = findParent(b);
            if (rank[r1] > rank[r2])
            {
                parent[r2] = r1;
            }
            else if (rank[r2] < rank[r1])
            {
                parent[r1] = r2;
            }
            else
            {
                rank[r1]++;
                parent[r2] = r1;
            }
        }
    };
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<tuple<int, int, int>> edges; // (cost, node1, node2)
        for (int i = 0; i < V; ++i)
        {
            for (auto &edge : adj[i])
            {
                int j = edge[0];
                int weight = edge[1];
                if (i < j)
                {
                    edges.emplace_back(weight, i, j);
                }
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int cost = 0;

        for (auto &edge : edges)
        {
            int weight, u, v;
            tie(weight, u, v) = edge;
            if (ds.findParent(u) != ds.findParent(v))
            {
                ds.unite(u, v);
                cost += weight;
            }
        }

        return cost;
    }
};

// Prim's Algorithm
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<bool> visited(V, false);

        int cost = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            int weight = front.first;
            int to = front.second;

            if (visited[to])
            {
                continue;
            }

            visited[to] = true;

            cost += weight;

            for (const auto &edge : adj[to])
            {
                int next_node = edge[0];
                int next_weight = edge[1];

                if (!visited[next_node])
                {
                    pq.push({next_weight, next_node});
                }
            }
        }

        return cost;
    }
};
