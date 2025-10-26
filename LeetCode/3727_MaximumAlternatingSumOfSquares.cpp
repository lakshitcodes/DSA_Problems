#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-alternating-sum-of-squares/

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for (auto &i : nums)
        {
            i = (i * i);
        }
        sort(nums.rbegin(), nums.rend());

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= (nums.size() + 1) / 2 - 1)
            {
                ans += nums[i];
            }
            else
            {
                ans -= nums[i];
            }
        }
        return ans;
    }
};