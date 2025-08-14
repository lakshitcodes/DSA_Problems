#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/largest-3-same-digit-number-in-string/

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        char ans;
        bool found = false;
        for (int i = 0; i < num.length() - 2; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                found = true;
                ans = max(ans, num[i]);
            }
        }
        if (!found)
        {
            return "";
        }
        return string(3, ans);
    }
};