#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/filling-bookcase-shelves/description

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = books.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++)
        {
            int curw = 0, curh = 0;
            int k = 1;
            while (k <= j)
            {
                curh = max(curh, books[j - k][1]);
                curw += books[j - k][0];
                if (curw > shelfWidth)
                {
                    break;
                }
                dp[j] = min(dp[j], dp[j - k] + curh);
                k += 1;
            }
        }
        return dp[n];
    }
};