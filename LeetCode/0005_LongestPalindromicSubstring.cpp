#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution
{
public:
    int expand(int left, int right, string s)
    {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int start = 0, maxLen = 1, n = s.length();
        if (n <= 1)
        {
            return s;
        }
        for (int i = 0; i < n; i++)
        {
            int len1 = expand(i, i, s);
            int len2 = expand(i, i + 1, s);
            int len = max(len1, len2);
            if (len > maxLen)
            {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};