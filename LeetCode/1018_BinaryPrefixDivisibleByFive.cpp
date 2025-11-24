#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/binary-prefix-divisible-by-five

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<bool> ans(nums.size(), false);
        int value = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            value = (value * 2 + nums[i]) % 5;
            if (value % 5 == 0)
            {
                ans[i] = true;
            }
        }
        return ans;
    }
};