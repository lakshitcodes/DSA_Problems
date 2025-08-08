#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/soup-servings/

class Solution
{
public:
    double soupServings(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (n > 4800)
        {
            return 1.0;
        }
        n = (n + 24) / 25;

        unordered_map<int, double> memo;
        return dp(n, n, memo);
    }
    double dp(int a, int b, unordered_map<int, double> &memo)
    {
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        if (a <= 0)
        {
            return 1.0;
        }
        if (b <= 0)
        {
            return 0.0;
        }
        int key = 5000 * a + b;
        if (memo.count(key))
        {
            return memo[key];
        }
        memo[key] = 0.25 * (dp(a - 4, b, memo) + dp(a - 3, b - 1, memo) + dp(a - 2, b - 2, memo) + dp(a - 1, b - 3, memo));
        return memo[key];
    }
};