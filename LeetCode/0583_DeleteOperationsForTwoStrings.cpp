#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        int lcs = dp[0][0];
        int ans = m + n - 2 * lcs;
        return ans;
    }
};