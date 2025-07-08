#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

class Solution
{
public:
    int solve(int index, vector<vector<int>> &events, int k, vector<vector<int>> &dp, vector<int> &next)
    {
        if (index >= events.size() || k == 0)
        {
            return 0;
        }
        if (dp[index][k] != -1)
        {
            return dp[index][k];
        }
        int include = events[index][2] + solve(next[index], events, k - 1, dp, next);
        int exclude = solve(index + 1, events, k, dp, next);
        return dp[index][k] = max(include, exclude);
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        vector<int> next(n, n);
        for (int i = 0; i < n; i++)
        {
            vector<int> finder = {events[i][1], INT_MAX, INT_MAX};
            next[i] = upper_bound(events.begin() + i + 1, events.end(), finder) - events.begin();
        }
        return solve(0, events, k, dp, next);
    }
};