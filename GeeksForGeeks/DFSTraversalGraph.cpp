#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, unordered_set<int> &visited, vector<int> &ans, vector<int> adj[])
    {
        if (visited.find(node) == visited.end())
        {
            visited.insert(node);
            ans.push_back(node);
            for (auto &i : adj[node])
            {
                dfs(i, visited, ans, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        unordered_set<int> visited;
        dfs(0, visited, ans, adj);
        return ans;
    }
};