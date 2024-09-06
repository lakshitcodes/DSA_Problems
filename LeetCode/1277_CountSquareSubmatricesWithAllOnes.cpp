#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems//count-square-submatrices-with-all-ones/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j])
                {
                    int minVal = INT_MAX;
                    if (i - 1 >= 0)
                    {
                        minVal = min(dp[i - 1][j], minVal);
                    }
                    else
                    {
                        minVal = 0;
                    }
                    if (j - 1 >= 0)
                    {
                        minVal = min(dp[i][j - 1], minVal);
                    }
                    else
                    {
                        minVal = 0;
                    }
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        minVal = min(dp[i - 1][j - 1], minVal);
                    }
                    else
                    {
                        minVal = 0;
                    }
                    dp[i][j] = 1 + minVal;
                    ans += dp[i][j];
                }
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return ans;
    }
};