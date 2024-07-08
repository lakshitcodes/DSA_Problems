#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution
{
public:
    int myAtoi(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        long long ans = 0;
        int idx = 0;
        int n = s.length();
        while (idx < n && s[idx] == ' ')
        {
            idx++;
        }
        bool negative = false;
        bool positive = false;
        if (s[idx] == '+')
        {
            idx++;
            positive = true;
        }
        if (s[idx] == '-')
        {
            idx++;
            negative = true;
        }
        if (positive && negative)
        {
            return 0;
        }
        for (; idx < n; idx++)
        {
            if (s[idx] >= '0' && s[idx] <= '9')
            {
                if (ans > INT_MAX)
                {
                    break;
                }
                ans *= 10;
                ans += s[idx] - '0';
            }
            else
            {
                break;
            }
        }
        if (negative)
        {
            ans *= -1;
        }
        if (ans > INT_MAX)
        {
            ans = INT_MAX;
        }

        if (ans < INT_MIN)
        {
            ans = INT_MIN;
        }
        return ans;
    }
};