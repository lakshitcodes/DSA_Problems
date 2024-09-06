#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // Recursion
    int solve(int index, string s)
    {
        if (index >= s.length())
            return 0;
        int ans = INT_MAX;
        for (int i = index; i < s.length(); i++)
        {
            if (isPalindrome(index, i, s))
            {
                ans = min(ans, 1 + solve(i + 1, s));
            }
        }
        return ans;
    }
    // Memoisation
    int solveTD(int index, string s, vector<int> &dp)
    {
        if (index >= s.length())
            return 0;
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int ans = INT_MAX;
        string temp = "";
        for (int i = index; i < s.length(); i++)
        {
            temp += s[i];
            if (isPalindrome(index, i, s))
            {
                ans = min(ans, 1 + solveTD(i + 1, s, dp));
            }
        }
        return dp[index] = ans;
    }
    // Tabulation
    int solveBU(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            int ans = INT_MAX;
            for (int i = index; i < s.length(); i++)
            {
                if (isPalindrome(index, i, s))
                {
                    ans = min(ans, 1 + dp[i + 1]);
                }
            }
            dp[index] = ans;
        }
        return dp[0];
    }
    int minCut(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Recursive Call
        // return solve(0,s)-1;

        // Memoisation Call
        // vector<int> dp(s.length() + 1, -1);
        // return solveTD(0, s, dp) - 1;

        // Tabulation
        return solveBU(s) - 1;
    }
};