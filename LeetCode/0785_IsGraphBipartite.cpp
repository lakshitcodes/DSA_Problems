#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = graph.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; start++)
        {
            if (color[start] == -1)
            {
                queue<int> q;
                color[start] = 0;
                q.push(start);

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    int currColor = color[node];
                    int newColor = 1 - currColor;

                    for (auto &neighbor : graph[node])
                    {
                        if (color[neighbor] == -1)
                        {
                            color[neighbor] = newColor;
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == currColor)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};