#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (str1[i] == str2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};