#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution
{
public:
    int numSub(string s) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int ones = 0;
        const int mod = 1e9 + 7;
        for (auto &i : s)
        {
            if (i == '0')
            {
                ones = 0;
            }
            else
            {
                ones++;
                ans = (ans + ones) % mod;
            }
        }
        return ans;
    }
};