#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int l = 0, r = 0;
        int maxLength = 0;
        int zeroCount = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                zeroCount++;
            }
            while (zeroCount > k)
            {
                if (nums[l] == 0)
                {
                    zeroCount--;
                }
                l++;
            }
            if (zeroCount <= k)
            {
                maxLength = max(r - l + 1, maxLength);
            }
            r++;
        }
        return maxLength;
    }
};
