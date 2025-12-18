#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/ const int N=1e5+1;
long long sum[N];
class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int n = prices.size(), k2 = k / 2;
        memset(sum, 0, sizeof(long long) * (n + 1));
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + 1LL * strategy[i] * prices[i];
        }

        long long modify = reduce(prices.begin() + k2, prices.begin() + k, 0LL);
        long long profit = max(sum[n], modify + sum[n] - sum[k]);

        for (int i = 1; i + k <= n; i++)
        {
            modify += prices[i + k - 1] - prices[i + k2 - 1];
            profit = max(profit, modify + sum[n] - sum[i + k] + sum[i]);
        }
        return profit;
    }
};