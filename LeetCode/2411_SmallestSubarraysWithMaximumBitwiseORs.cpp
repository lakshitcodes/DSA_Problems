#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> last(30, 0);
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 30; j++)
            {
                if (nums[i] & (1 << j))
                {
                    last[j] = i;
                }
                ans[i] = max(ans[i], last[j] - i + 1);
            }
        }
        return ans;
    }
};