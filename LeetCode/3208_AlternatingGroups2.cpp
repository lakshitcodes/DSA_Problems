#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/alternating-groups-ii/

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ans = 0, count = 1, n = colors.size();
        for (int i = 1; i < n + k - 1; i++)
        {
            if (colors[i % n] != colors[(n + i - 1) % n])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count >= k)
            {
                ans++;
            }
        }

        return ans;
    }
};