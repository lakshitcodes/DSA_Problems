#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<long long> res(k + 1), bought(k, -1e9), sold(k);
        for (int a : prices)
        {
            for (int j = k; j >= 1; --j)
            {
                res[j] = max({res[j], bought[j - 1] + a, sold[j - 1] - a});
                bought[j - 1] = max(bought[j - 1], res[j - 1] - a);
                sold[j - 1] = max(sold[j - 1], res[j - 1] + a);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};