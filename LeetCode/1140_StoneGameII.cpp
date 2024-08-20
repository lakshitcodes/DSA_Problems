#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-ii/description/

class Solution
{
public:
    vector<vector<vector<pair<int, int>>>> dp;

    pair<int, int> solve(int index, int M, int chance, vector<int> &piles)
    {
        if (index >= piles.size())
        {
            return {0, 0};
        }

        if (dp[index][M][chance] != make_pair(-1, -1))
        {
            return dp[index][M][chance];
        }

        pair<int, int> ans = {0, 0};
        int total = 0;

        if (chance == 1)
        {
            ans.first = INT_MIN;
            for (int i = 1; i <= 2 * M && index + i <= piles.size(); i++)
            {
                total += piles[index + i - 1];
                auto ahead = solve(index + i, max(M, i), 0, piles);
                ahead.first += total;
                if (ahead.first > ans.first)
                {
                    ans = ahead;
                }
            }
        }
        else
        {
            ans.second = INT_MIN;
            for (int i = 1; i <= 2 * M && index + i <= piles.size(); i++)
            {
                total += piles[index + i - 1];
                auto ahead = solve(index + i, max(M, i), 1, piles);
                ahead.second += total;
                if (ahead.second > ans.second)
                {
                    ans = ahead;
                }
            }
        }

        return dp[index][M][chance] = ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        dp = vector<vector<vector<pair<int, int>>>>(n, vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(2, {-1, -1})));

        auto ans = solve(0, 1, 1, piles);
        return ans.first;
    }
};
