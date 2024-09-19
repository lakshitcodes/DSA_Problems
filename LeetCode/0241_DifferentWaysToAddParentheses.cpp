#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution
{
public:
    bool isOperand(char c) { return c == '+' || c == '-' || c == '*'; }
    vector<int> solve(int start, int end, string exp, unordered_map<string, vector<int>> &dp)
    {
        if (start > end)
        {
            return {0};
        }
        if (start == end)
        {
            return {exp[start] - '0'};
        }
        if (start + 1 == end)
        {
            if (isdigit(exp[start]) && isdigit(exp[end]))
            {
                return {(exp[start] - '0') * 10 + (exp[end] - '0')};
            }
        }
        string mask = to_string(start) + '_' + to_string(end);
        if (dp.find(mask) != dp.end())
        {
            return dp[mask];
        }
        vector<int> ans;
        for (int i = start + 1; i < end; i++)
        {
            if (isOperand(exp[i]))
            {
                auto left = solve(start, i - 1, exp, dp);
                auto right = solve(i + 1, end, exp, dp);
                if (exp[i] == '+')
                {
                    for (auto &l : left)
                    {
                        for (auto &r : right)
                        {
                            ans.push_back(l + r);
                        }
                    }
                }
                if (exp[i] == '-')
                {
                    for (auto &l : left)
                    {
                        for (auto &r : right)
                        {
                            ans.push_back(l - r);
                        }
                    }
                }
                if (exp[i] == '*')
                {
                    for (auto &l : left)
                    {
                        for (auto &r : right)
                        {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }
        return dp[mask] = ans;
    }
    vector<int> diffWaysToCompute(string exp)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<string, vector<int>> dp;
        return solve(0, exp.length() - 1, exp, dp);
    }
};