#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> distances(n, vector<int>(n, 1e5));
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            distances[u][v] = weight;
            distances[v][u] = weight;
        }
        for (int i = 0; i < n; i++)
        {
            distances[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int oc = distances[i][j];
                    int nc = distances[i][k] + distances[k][j];
                    if (nc < oc)
                    {
                        distances[i][j] = nc;
                    }
                }
            }
        }
        unordered_map<int, int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (distances[i][j] <= distanceThreshold)
                    {
                        ans[i]++;
                    }
                }
            }
        }

        int currCount = INT_MAX;
        int currAns = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (ans[i] < currCount)
            {
                currCount = ans[i];
                currAns = i;
            }
        }
        return currAns;
    }
};