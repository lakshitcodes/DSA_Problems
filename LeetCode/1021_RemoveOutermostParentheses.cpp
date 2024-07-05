#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-outermost-parentheses/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        string res = "";
        int opened = 0;
        for (char c : s)
        {
            if (c == '(' && opened++ > 0)
                res += c;
            if (c == ')' && opened-- > 1)
                res += c;
        }
        return res;
    }
};