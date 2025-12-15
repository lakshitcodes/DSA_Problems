#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 1;
        int curr = 1;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] + 1 == prices[i - 1])
            {
                ans += curr + 1;
                curr++;
            }
            else
            {
                ans += 1;
                curr = 1;
            }
        }
        return ans;
    }
};