#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int zero = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
        }
        long long currVal = 0;
        long long multiplier = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                zero++;
                currVal += multiplier;
            }
            if (currVal > k)
            {
                return zero - 1;
            }
            if (multiplier > k / 2)
            {
                return zero;
            }
            multiplier *= 2;
        }
        return zero;
    }
};