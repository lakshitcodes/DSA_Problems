#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/description/

class Solution
{
public:
    long long minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<pair<int, int>> cuts;
        for (int i = 0; i < horizontalCut.size(); i++)
        {
            cuts.push_back({horizontalCut[i], 0});
        }
        for (int i = 0; i < verticalCut.size(); i++)
        {
            cuts.push_back({verticalCut[i], 1});
        }
        sort(cuts.begin(), cuts.end(), greater<pair<int, int>>());
        long long ans = 0;
        long long horizontalComponents = 1, verticalComponents = 1;
        for (auto &cut : cuts)
        {
            if (cut.second == 0)
            {
                ans += cut.first * verticalComponents;
                horizontalComponents++;
            }
            else
            {
                ans += cut.first * horizontalComponents;
                verticalComponents++;
            }
        }
        return ans;
    }
};