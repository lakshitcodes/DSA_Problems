#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/alternating-groups-i/description/

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        if (colors.size() <= 1)
        {
            return 0;
        }
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ans = 0;
        for (int i = 0; i < colors.size() - 2; i++)
        {
            if (colors[i] != colors[i + 1] && colors[i] == colors[i + 2])
            {
                ans++;
            }
        }
        if (colors[0] != colors[colors.size() - 1] && colors[0] == colors[colors.size() - 2])
        {
            ans++;
        }
        if (colors[0] != colors[colors.size() - 1] && colors[1] == colors[colors.size() - 1])
        {
            ans++;
        }
        return ans;
    }
};