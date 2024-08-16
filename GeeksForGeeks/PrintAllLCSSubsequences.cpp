#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

class Solution
{
public:
    vector<string> solve(int i, int j, string &s, string &t, vector<vector<int>> &dp, unordered_map<string, vector<string>> &memo)
    {
        if (i == s.size() || j == t.size())
        {
            return {""};
        }

        string key = to_string(i) + "_" + to_string(j);

        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        vector<string> result;

        if (s[i] == t[j])
        {
            vector<string> temp = solve(i + 1, j + 1, s, t, dp, memo);
            for (string &str : temp)
            {
                result.push_back(s[i] + str);
            }
        }
        else
        {
            if (dp[i + 1][j] >= dp[i][j + 1])
            {
                result = solve(i + 1, j, s, t, dp, memo);
            }
            if (dp[i][j + 1] >= dp[i + 1][j])
            {
                vector<string> temp = solve(i, j + 1, s, t, dp, memo);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return memo[key] = result;
    }

    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        unordered_map<string, vector<string>> memo;
        return solve(0, 0, s, t, dp, memo);
    }
};