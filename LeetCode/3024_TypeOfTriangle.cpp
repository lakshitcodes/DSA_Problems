#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/type-of-triangle

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])
        {
            return "none";
        }
        if (nums[0] == nums[2])
        {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2])
        {
            return "isosceles";
        }
        return "scalene";
    }
};