#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/

class Solution
{
public:
    long long countStableSubarrays(vector<int> &a)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long pref = 0;
        unordered_map<long long, unordered_map<long long, long long>> mp;
        long long ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (mp.count(a[i]) && mp[a[i]].count(pref - a[i]))
            {
                ans += mp[a[i]][pref - a[i]];
            }
            pref += a[i];
            mp[a[i]][pref]++;
            if (i > 0 && a[i] == 0 && a[i - 1] == 0)
            {
                ans--;
            }
        }
        return ans;
    }
};