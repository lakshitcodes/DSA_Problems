#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        while (r < s.length())
        {
            auto it = mp.find(s[r]);

            if (it != mp.end() and it->second >= l)
            {
                l = it->second + 1;
            }
            ans = max(r - l + 1, ans);
            mp[s[r]] = r;
            r++;
        }
        return ans;
    }
};