#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/generate-parentheses

class Solution
{
public:
    void solve(vector<string> &ans, string curr, int open, int closed, int n)
    {
        if (open > n || closed > n)
        {
            return;
        }
        if (open == closed && closed == n)
        {
            ans.push_back(curr);
            return;
        }
        if (closed > open)
        {
            return;
        }
        solve(ans, curr + '(', open + 1, closed, n);
        solve(ans, curr + ')', open, closed + 1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};