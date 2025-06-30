#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        int ans = 0;
        for (auto &i : mp)
        {
            if (mp.count(i.first + 1))
            {
                ans = max(ans, i.second + mp[i.first + 1]);
            }
        }
        return ans;
    }
};