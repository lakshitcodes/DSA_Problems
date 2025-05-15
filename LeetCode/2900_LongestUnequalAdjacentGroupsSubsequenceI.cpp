#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> ans;
        int prev = 0;
        ans.push_back(words[0]);
        for (int i = 1; i < groups.size(); i++)
        {
            if (groups[i] != groups[prev])
            {
                ans.push_back(words[i]);
                prev = i;
            }
        }
        return ans;
    }
};