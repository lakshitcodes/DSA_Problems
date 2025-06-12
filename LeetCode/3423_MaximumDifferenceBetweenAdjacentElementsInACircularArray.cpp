#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxDiff = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++)
        {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i - 1]));
        }
        return maxDiff;
    }
};