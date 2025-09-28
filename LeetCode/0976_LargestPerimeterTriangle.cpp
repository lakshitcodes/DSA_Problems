#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/largest-perimeter-triangle/

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 1; i--)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};