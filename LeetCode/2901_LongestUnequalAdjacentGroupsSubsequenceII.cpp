#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/

class Solution
{
public:
    bool hamming(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                diff++;
            }
        }
        return diff <= 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = words.size();
        vector<int> dp(n, 0);
        vector<int> idx(n, n);
        int maxi = 0;
        int maxiInd = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (groups[i] != groups[j] && hamming(words[i], words[j]))
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        idx[i] = j;
                    }
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                maxiInd = i;
            }
        }
        vector<string> ans;
        int index = maxiInd;
        while (index < n)
        {
            ans.push_back(words[index]);
            index = idx[index];
        }
        return ans;
    }
};