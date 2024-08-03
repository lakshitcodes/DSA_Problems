#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto &i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        vector<bool> visited(numCourses, false);
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int processed = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            processed++;
            if (!visited[front])
            {
                visited[front] = true;
                for (auto &i : adj[front])
                {
                    if (!visited[i] && --inDegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return processed == numCourses;
    }
};