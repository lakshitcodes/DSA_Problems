#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/course-schedule-ii/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (auto &i : prerequisites)
        {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                // ans.push_back(i);
                q.push(i);
            }
        }
        int processed = 0;
        vector<bool> visited(numCourses, false);
        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            processed++;
            if (!visited[element])
            {
                visited[element] = true;
                ans.push_back(element);
                for (auto &neighbor : adj[element])
                {
                    if (!visited[neighbor] && --inDegree[neighbor] == 0)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
        if (numCourses == processed)
        {
            return ans;
        }
        return {};
    }
};