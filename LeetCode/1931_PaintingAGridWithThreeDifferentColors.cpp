#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<unordered_map<string, int>> dp;
    int solve(int n, string prev, vector<string> &cand)
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
        for (int i = 0; i < cand.size(); i++)
        {
            bool valid = true;
            for (int j = 0; j < prev.size(); j++)
            {
                if (prev[j] == cand[i][j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans = (ans + solve(n - 1, cand[i], cand)) % mod;
        }
        return dp[n][prev] = ans;
    }
    void fillCandidate(int m, string curr, vector<string> &cand)
    {
        if (m == 0)
        {
            cand.push_back(curr);
            return;
        }
        if (curr.empty() || curr.back() != 'R')
        {
            fillCandidate(m - 1, curr + 'R', cand);
        }
        if (curr.empty() || curr.back() != 'G')
        {
            fillCandidate(m - 1, curr + 'G', cand);
        }
        if (curr.empty() || curr.back() != 'B')
        {
            fillCandidate(m - 1, curr + 'B', cand);
        }
    }
    int colorTheGrid(int m, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        dp.resize(n + 1);
        vector<string> cand;
        fillCandidate(m, "", cand);
        int ans = 0;
        for (int i = 0; i < cand.size(); i++)
        {
            ans = (ans + solve(n - 1, cand[i], cand)) % mod;
        }
        return ans;
    }
};