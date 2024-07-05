#include <bits/stdc++.h>
using namespace std;

// https : // leetcode.com/problems/largest-odd-number-in-string/

class Solution
{
public:
    string largestOddNumber(string num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int index = -1;
        for (int i = 0; i < num.length(); i++)
        {
            if ((num[i] - '0') % 2)
            {
                index = i;
            }
        }
        if (index == -1)
        {
            return "";
        }
        string ans = num.substr(0, index + 1);
        return ans;
    }
};