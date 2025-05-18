#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<unordered_map<string, int>> dp;
    int solve(int n, string prev, vector<string> &curr)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[n].count(prev))
        {
            return dp[n][prev];
        }
        int ans = 0;
        for (int i = 0; i < curr.size(); i++)
        {
            bool valid = true;
            for (int j = 0; j < prev.size(); j++)
            {
                if (prev[j] == curr[i][j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ans = (ans + solve(n - 1, curr[i], curr)) % mod;
            }
        }
        return dp[n][prev] = ans;
    }
    void fillCand(int n, string curr, vector<string> &cand)
    {
        if (n == 0)
        {
            cand.push_back(curr);
            return;
        }
        if (curr.empty() || curr.back() != 'R')
            fillCand(n - 1, curr + 'R', cand);
        if (curr.empty() || curr.back() != 'G')
            fillCand(n - 1, curr + 'G', cand);
        if (curr.empty() || curr.back() != 'B')
            fillCand(n - 1, curr + 'B', cand);
    }
    int numOfWays(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> cand;
        fillCand(3, "", cand);
        dp.resize(n + 1);
        int ans = 0;
        for (int i = 0; i < cand.size(); i++)
        {
            ans = (ans + solve(n - 1, cand[i], cand)) % mod;
        }
        return ans;
    }
};