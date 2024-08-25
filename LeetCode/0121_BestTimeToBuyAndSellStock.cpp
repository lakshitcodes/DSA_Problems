#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/q

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int minimum = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }
        return profit;
    }
};