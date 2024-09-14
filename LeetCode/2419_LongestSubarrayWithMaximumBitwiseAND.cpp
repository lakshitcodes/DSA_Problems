#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxElement = *max_element(nums.begin(), nums.end());
        int start = -1, end = -1;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxElement)
            {
                if (start == -1)
                {
                    start = i;
                    end = i;
                }
                if (i == end + 1 && end != -1)
                {
                    end++;
                }
            }
            else
            {
                ans = max(ans, end - start + 1);
                end = -1;
                start = -1;
            }
        }
        return max(ans, end - start + 1);
    }
};