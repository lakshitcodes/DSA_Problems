#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-liucky-number-in-an-array/

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, int> mp;
        for (auto &i : arr)
        {
            mp[i]++;
        }
        int ans = -1;
        for (auto &i : mp)
        {
            if (i.first == i.second)
            {
                ans = max(ans, i.first);
            }
        }
        return ans;
    }
};