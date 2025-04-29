#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int freq = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == maxi)
            {
                freq++;
            }
            while (freq >= k)
            {
                ans += nums.size() - r;
                if (nums[l] == maxi)
                {
                    freq--;
                }
                l++;
            }
        }
        return ans;
    }
};