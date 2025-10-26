#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/conut-ways-to-choose-coprime-integers-from-rows

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int solve(int idx, int GCD, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        int m = mat.size();
        if (idx == m)
        {
            if (GCD == 1)
            {
                return 1;
            }
            return 0;
        }

        if (dp[idx][GCD] != -1)
        {
            return dp[idx][GCD];
        }
        long long res = 0;
        for (int i = 0; i < mat[0].size(); i++)
        {
            int newGCD;
            if (idx == 0)
            {
                newGCD = mat[idx][i];
            }
            else
            {
                newGCD = __gcd(GCD, mat[idx][i]);
            }

            res = (res + solve(idx + 1, newGCD, mat, dp)) % MOD;
        }
        return dp[idx][GCD] = res;
    }
    int countCoprime(vector<vector<int>> &mat)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(151, -1));
        return solve(0, 0, mat, dp);
    }
};