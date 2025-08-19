#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        long long curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                curr++;
            }
            else
            {
                ans += curr * (curr + 1) / 2;
                curr = 0;
            }
        }
        ans += curr * (curr + 1) / 2;
        return ans;
    }
};