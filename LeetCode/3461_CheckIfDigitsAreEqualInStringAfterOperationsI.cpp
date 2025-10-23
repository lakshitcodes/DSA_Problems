#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        while (s.length() > 2)
        {
            string curr = "";
            for (int i = 0; i < s.length() - 1; i++)
            {
                curr += '0' + ((s[i] - '0') + (s[i + 1] - '0')) % 10;
            }
            s = curr;
        }
        return s[0] == s[1];
    }
};