#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/rearranging-fruits

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, int> total, b1, b2;
        long long minEle = INT_MAX;
        for (auto &i : basket1)
        {
            b1[i]++;
            total[i]++;
            minEle = min((long long)i, minEle);
        }
        for (auto &i : basket2)
        {
            b2[i]++;
            total[i]++;
            minEle = min((long long)i, minEle);
        }
        long long count = 0;
        vector<long long> swapCosts;
        for (auto &i : total)
        {
            if (i.second % 2)
            {
                return -1;
            }
            int diff = i.second / 2 - b1[i.first];
            for (int j = 0; j < abs(diff); j++)
            {
                swapCosts.push_back(i.first);
            }
        }
        long long ans = 0;
        sort(swapCosts.begin(), swapCosts.end());
        for (int i = 0; i < swapCosts.size() / 2; i++)
        {
            ans += min(swapCosts[i], 2LL * minEle);
        }
        return ans;
    }
};