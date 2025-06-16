#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = -1;
        int minElement = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            ans = max(ans, nums[i] - minElement);
            minElement = min(nums[i], minElement);
        }
        return ans == 0 ? -1 : ans;
    }
};