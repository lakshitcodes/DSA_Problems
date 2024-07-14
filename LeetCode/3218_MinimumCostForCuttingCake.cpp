#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/

class Solution
{
public:
    int minimumCost(int m, int n, vector<int> &horizontalCuts,
                    vector<int> &verticalCuts)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<pair<int, int>> cuts;
        for (int i = 0; i < horizontalCuts.size(); i++)
        {
            cuts.push_back({horizontalCuts[i], 0});
        }
        for (int j = 0; j < verticalCuts.size(); j++)
        {
            cuts.push_back({verticalCuts[j], 1});
        }

        sort(cuts.begin(), cuts.end(), greater<pair<int, int>>());

        int horizontalSegments = 1;
        int verticalSegments = 1;
        int totalCost = 0;

        for (auto &cut : cuts)
        {
            if (cut.second == 0)
            {
                totalCost += cut.first * verticalSegments;
                horizontalSegments++;
            }
            else
            {
                totalCost += cut.first * horizontalSegments;
                verticalSegments++;
            }
        }

        return totalCost;
    }
};