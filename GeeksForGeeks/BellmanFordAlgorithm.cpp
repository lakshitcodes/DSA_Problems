#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> distances(V, 1e8);
        distances[S] = 0;
        for (int i = 1; i <= V; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];
                if (distances[u] + cost < distances[v] && distances[u] != 1e8)
                {
                    if (i == V)
                    {
                        return {-1};
                    }
                    distances[v] = distances[u] + cost;
                }
            }
        }
        return distances;
    }
};