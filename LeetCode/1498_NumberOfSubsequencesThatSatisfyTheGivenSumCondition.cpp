#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i, r = n - 1, j = -1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] <= target)
                {
                    j = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            if (j >= i)
            {
                ans = (ans + pow2[j - i]) % mod;
            }
        }
        return ans;
    }
};