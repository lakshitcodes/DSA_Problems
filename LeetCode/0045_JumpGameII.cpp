#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/jump-game-ii/

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return 0;
        }

        int jumps = 0;
        int maxReach = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; ++i)
        {

            maxReach = std::max(maxReach, i + nums[i]);

            if (i == currentEnd)
            {
                jumps++;
                currentEnd = maxReach;

                if (currentEnd >= n - 1)
                {
                    break;
                }
            }
        }

        return jumps;
    }
};
