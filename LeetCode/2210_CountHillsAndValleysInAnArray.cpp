#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> uniq;
        for (auto &i : nums)
        {
            if (uniq.empty() || uniq.back() != i)
            {
                uniq.push_back(i);
            }
        }
        int ans = 0;
        for (int i = 1; i < uniq.size() - 1; i++)
        {
            if (uniq[i] > uniq[i + 1] && uniq[i] > uniq[i - 1])
            {
                ans++;
            }
            if (uniq[i] < uniq[i + 1] && uniq[i] < uniq[i - 1])
            {
                ans++;
            }
        }
        return ans;
    }
};