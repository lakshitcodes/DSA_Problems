#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-erasure-value/

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, int> prev;
        int maxi = 0;
        int currSum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (prev.count(nums[r]) && prev[nums[r]] >= l)
            {
                int last = prev[nums[r]];
                while (l <= last)
                {
                    currSum -= nums[l];
                    l++;
                }
            }
            currSum += nums[r];
            prev[nums[r]] = r;
            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};