#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int c = count(nums.begin(), nums.end(), 1);
        if (c)
        {
            return n - c;
        }
        int res = 1e7;
        for (int i = 0; i < n; i++)
        {
            int g = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                g = __gcd(g, nums[j]);
                if (g == 1)
                {
                    res = min(res, j - i + (n - 1));
                    break;
                }
            }
        }
        return res == 1e7 ? -1 : res;
    }
};