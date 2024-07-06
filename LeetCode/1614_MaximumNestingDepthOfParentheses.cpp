#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution
{
public:
    int maxDepth(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int maxDepth = 0, currDepth = 0;
        for (auto &c : s)
        {
            if (c == '(')
            {
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            }
            else if (c == ')')
            {
                currDepth--;
            }
        }
        return maxDepth;
    }
};