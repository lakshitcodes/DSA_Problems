#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    void solve(int index, string digits, string curr, unordered_map<char, string> &mp, vector<string> &ans)
    {
        if (index == digits.length())
        {
            ans.push_back(curr);
            return;
        }
        for (char c : mp[digits[index]])
        {
            curr += c;
            solve(index + 1, digits, curr, mp, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (digits.empty())
        {
            return {};
        }

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        solve(0, digits, "", mp, ans);
        return ans;
    }
};
