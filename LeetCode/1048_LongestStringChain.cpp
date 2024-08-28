#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-string-chain/

class Solution
{
public:
    static bool comparator(string &a, string &b)
    {
        return a.length() < b.length();
    }
    bool isPoss(string a, string b)
    {
        if (b.length() != a.length() + 1)
            return false;
        int first = 0, second = 0;
        while (second < b.length())
        {
            if (a[first] == b[second])
            {
                first++;
                second++;
            }
            else
            {
                second++;
            }
        }
        return first == a.length() && second == b.length();
    }
    int longestStrChain(vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(words.begin(), words.end(), comparator);
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPoss(words[j], words[i]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};