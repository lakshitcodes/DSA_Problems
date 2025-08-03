#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/trionic-array-i/

class Solution
{
public:
    bool isValid(vector<int> &nums, int p, int q)
    {
        int n = nums.size();
        for (int i = 1; i <= p; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                return false;
            }
        }
        for (int i = p; i < q; i++)
        {
            if (nums[i] <= nums[i + 1])
            {
                return false;
            }
        }
        for (int i = q + 1; i < n; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                return false;
            }
        }
        return true;
    }
    bool isTrionic(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        if (n == 3)
        {
            return false;
        }
        for (int p = 1; p < n - 1; p++)
        {
            for (int q = p + 1; q < n - 1; q++)
            {
                if (isValid(nums, p, q))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
