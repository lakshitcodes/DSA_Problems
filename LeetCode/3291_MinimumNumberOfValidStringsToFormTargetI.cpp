#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/

class Solution
{
public:
    int solveTab(string target, unordered_set<string> &dict)
    {
        int n = target.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int index = n - 1; index >= 0; index--)
        {
            int ans = 1e8;
            for (auto &word : dict)
            {
                int i = 0;
                int indext = index;
                if (word[i] != target[indext])
                {
                    continue;
                }
                while (i < word.length() && indext < n &&
                       word[i] == target[indext])
                {
                    i++;
                    indext++;
                    ans = min(ans, 1 + dp[indext]);
                }
            }
            dp[index] = ans;
        }
        return dp[0];
    }
    int minValidStrings(vector<string> &words, string target)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<string> dict(words.begin(), words.end());
        vector<int> dp(target.length() + 1, -1);
        int result = solveTab(target, dict);
        return result == 1e8 ? -1 : result;
    }
};
