#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution
{
public:
    bool isPossible(int mid, vector<int> &nums, int p)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] <= mid)
            {
                p--;
                i++;
            }
        }
        return p <= 0;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0];
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, nums, p))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};