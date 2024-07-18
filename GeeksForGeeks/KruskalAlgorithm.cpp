#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    class DisjointSet
    {
    public:
        int *parent, *rank;
        DisjointSet(int n)
        {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        ~DisjointSet()
        {
            delete[] parent;
            delete[] rank;
        }
        int findParent(int i)
        {
            if (i == parent[i])
            {
                return i;
            }
            parent[i] = findParent(parent[i]);
            return parent[i];
        }
        void unite(int v1, int v2)
        {
            int parentV1 = findParent(v1);
            int parentV2 = findParent(v2);
            if (rank[parentV1] > rank[parentV2])
            {
                parent[parentV2] = parentV1;
            }
            else if (rank[parentV1] < rank[parentV2])
            {
                parent[parentV1] = parentV2;
            }
            else
            {
                rank[parentV1]++;
                parent[parentV2] = parentV1;
            }
        }
    };

    struct compare
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        }
    };

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;

        // Convert adjacency list to edge list
        for (int i = 0; i < V; i++)
        {
            for (auto &edge : adj[i])
            {
                edges.push_back({i, edge[0], edge[1]});
            }
        }

        // Sort edges based on weight
        sort(edges.begin(), edges.end(), compare());

        DisjointSet mySet(V);
        int totalCost = 0;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            int v1 = mySet.findParent(u);
            int v2 = mySet.findParent(v);
            if (v1 != v2)
            {
                mySet.unite(v1, v2);
                totalCost += cost;
            }
        }

        return totalCost;
    }
};