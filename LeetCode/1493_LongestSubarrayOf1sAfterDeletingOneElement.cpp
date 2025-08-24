#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int curr = 0;
        int zero = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
            {
                zero++;
            }
            else
            {
                curr++;
            }
            while (zero > 1)
            {
                if (nums[l] == 0)
                {
                    zero--;
                }
                else
                {
                    curr--;
                }
                l++;
            }
            ans = max(ans, curr);
        }

        ans = max(ans, curr);
        return ans == nums.size() ? ans - 1 : ans;
    }
};