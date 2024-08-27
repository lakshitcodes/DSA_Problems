#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/path-with-maximum-probability/

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<pair<double, int>> pq;
        unordered_map<int, vector<pair<int, double>>> mp;
        for (int i = 0; i < edges.size(); i++)
        {
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        pq.push({1.0, start_node});
        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;
        while (!pq.empty())
        {
            double prob = pq.top().first;
            int element = pq.top().second;
            pq.pop();
            if (element == end_node)
            {
                return prob;
            }
            for (auto &i : mp[element])
            {
                int next = i.first;
                double newCost = i.second * prob;
                if (newCost > probabilities[next])
                {
                    pq.push({newCost, next});
                    probabilities[next] = newCost;
                }
            }
        }
        return 0;
    }
};