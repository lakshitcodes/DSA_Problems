#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-removals-to-balance-arrays

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = nums.size() - 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int lo = i + 1, hi = n - 1;
            int idx = i;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if ((long long)nums[mid] <= (long long)nums[i] * (long long)k)
                {
                    idx = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            ans = min(ans, i + n - 1 - idx);
        }
        return ans;
    }
};