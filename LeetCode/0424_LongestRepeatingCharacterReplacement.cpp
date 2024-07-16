#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int l = 0, r = 0, maxLength = 0, maxFreq = 0;
        unordered_map<char, int> mp;
        while (r < s.length())
        {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            while (r - l + 1 - maxFreq > k)
            {
                mp[s[l]]--;
                l++;
                maxFreq = 0;
                for (auto i : mp)
                {
                    maxFreq = max(maxFreq, i.second);
                }
            }
            if (r - l + 1 - maxFreq <= k)
            {
                maxLength = max(maxLength, r - l + 1);
            }
            r++;
        }
        return maxLength;
    }
};

// Optimised Approach
// Removed the scanning to reduce the maxFreq because only when maxFreq increases, our ans will be increasing
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int l = 0, r = 0, maxLength = 0, maxFreq = 0;
        unordered_map<char, int> mp;
        while (r < s.length())
        {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            while (r - l + 1 - maxFreq > k)
            {
                mp[s[l]]--;
                l++;
            }
            if (r - l + 1 - maxFreq <= k)
            {
                maxLength = max(maxLength, r - l + 1);
            }
            r++;
        }
        return maxLength;
    }
};