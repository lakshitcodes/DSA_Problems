#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/build-a-matrix-with-conditions/description/

class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                    vector<vector<int>> &colConditions)
    {
        unordered_map<int, vector<int>> graph;
        for (auto &edge : rowConditions)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> rowOrder = topologicalSort(graph, k);
        graph.clear();
        for (auto &edge : colConditions)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> colOrder = topologicalSort(graph, k);
        if (colOrder.empty() || rowOrder.empty())
        {
            return {};
        }

        unordered_map<int, pair<int, int>> valuePositions;
        for (int i = 0; i < k; i++)
        {
            valuePositions[rowOrder[i]].first = i;
            valuePositions[colOrder[i]].second = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++)
        {
            int row = valuePositions[i].first;
            int col = valuePositions[i].second;
            ans[row][col] = i;
        }
        return ans;
    }

private:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &graph, int k)
    {
        unordered_set<int> visited;
        unordered_set<int> currPath;
        vector<int> res;
        for (int src = 1; src <= k; src++)
        {
            if (!dfs(src, graph, visited, currPath, res))
            {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool dfs(int src, unordered_map<int, vector<int>> &graph,
             unordered_set<int> &visited, unordered_set<int> &currPath,
             vector<int> &res)
    {
        if (currPath.count(src))
        {
            return false;
        }
        if (visited.count(src))
        {
            return true;
        }
        visited.insert(src);
        currPath.insert(src);
        for (auto neighbor : graph[src])
        {
            if (!dfs(neighbor, graph, visited, currPath, res))
            {
                return false;
            }
        }
        currPath.erase(src);
        res.push_back(src);
        return true;
    }
};