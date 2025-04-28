#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        long long l = 0, r = 0, currSum = 0;
        int n = nums.size();
        while (r < n)
        {
            currSum += nums[r];

            while (currSum * (r - l + 1) >= k)
            {
                currSum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};