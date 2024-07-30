#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        unordered_set<int> visited;
        vector<int> ans;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (visited.count(front) == 0)
            {
                ans.push_back(front);
                visited.insert(front);
                for (auto &i : adj[front])
                {
                    if (visited.find(i) == visited.end())
                    {
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};