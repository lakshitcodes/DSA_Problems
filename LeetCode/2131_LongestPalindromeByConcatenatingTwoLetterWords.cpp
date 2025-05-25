#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string, int> dict;
        int pairs = 0;
        for (auto &s : words)
        {
            string rev = string(1, s[1]) + s[0];
            if (dict[rev] > 0)
            {
                pairs++;
                dict[rev]--;
            }
            else
            {
                dict[s]++;
            }
        }
        int ans = pairs * 4;
        for (auto &i : dict)
        {
            if (i.first[0] == i.first[1] && i.second)
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};