#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    class DijkstraNode
    {
    public:
        int name;
        int cost;
        DijkstraNode(int node, int weight)
        {
            this->name = node;
            this->cost = weight;
        }
    };
    struct compare
    {

        bool operator()(DijkstraNode *a, DijkstraNode *b)
        {
            return a->cost > b->cost;
        }
    };
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V, false);
        priority_queue<DijkstraNode *, vector<DijkstraNode *>, compare> pq;
        pq.push(new DijkstraNode(S, 0));
        vector<int> distances(V, INT_MAX);
        distances[S] = 0;
        while (!pq.empty())
        {
            auto frontElement = pq.top();
            pq.pop();
            if (!visited[frontElement->name])
            {
                visited[frontElement->name] = true;
                for (auto element : adj[frontElement->name])
                {
                    int newCost = frontElement->cost + element[1];
                    if (!visited[element[0]] && distances[element[0]] > newCost)
                    {
                        pq.push(new DijkstraNode(element[0], newCost));
                        distances[element[0]] = newCost;
                    }
                }
            }
        }
        return distances;
    }
};