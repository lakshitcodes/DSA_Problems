#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/word-break/description/

class Solution
{
public:
    bool solve(string s, int idx, unordered_set<string> &dict, vector<int> &dp)
    {
        if (idx == s.length())
        {
            return true;
        }
        int index = idx;
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        string curr = "";
        for (; idx < s.length(); idx++)
        {
            curr += s[idx];
            if (dict.find(curr) != dict.end())
            {
                bool flag = solve(s, idx + 1, dict, dp);
                if (flag)
                {
                    dp[idx] = true;
                    return true;
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (auto i : wordDict)
        {
            dict.insert(i);
        }
        vector<int> dp(s.length() + 1, -1);
        return solve(s, 0, dict, dp);
    }
};