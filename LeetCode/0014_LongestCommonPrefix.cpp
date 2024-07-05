#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-common-prefix/description/

class Solution
{
public:
    string findPrefix(string a, string b)
    {
        int n = min(a.length(), b.length());
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                ans += a[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        string prev = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            prev = findPrefix(prev, strs[i]);
            if (prev.length() == 0)
            {
                return "";
            }
        }
        return prev;
    }
};