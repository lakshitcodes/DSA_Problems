#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int freqCount = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < freqCount; i++)
        {
            nums.push_back(nums[i]);
        }
        int ans = INT_MAX;
        int zeroCount = 0;
        for (int i = 0; i < freqCount; i++)
        {
            if (nums[i] == 0)
            {
                zeroCount++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, zeroCount);
            if (nums[i - 1] == 0)
            {
                zeroCount--;
            }
            if (nums[freqCount + i - 1] == 0)
            {
                zeroCount++;
            }
        }
        ans = min(ans, zeroCount);
        return ans;
    }
};