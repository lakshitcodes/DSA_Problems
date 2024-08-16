#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-distance-in-arrays/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxi = arrays[0].back();
        int mini = arrays[0][0];
        int ans = 0;
        for (int i = 1; i < arrays.size(); i++)
        {
            ans = max({maxi - arrays[i][0], arrays[i].back() - mini, ans});
            maxi = max(maxi, arrays[i].back());
            mini = min(mini, arrays[i][0]);
        }
        return ans;
    }
};