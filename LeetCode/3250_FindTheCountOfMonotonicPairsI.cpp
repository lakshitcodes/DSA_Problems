#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/

const int MOD = 1000000007;

class Solution
{
public:
    unordered_map<long long, int> memo;

    int solve(int index, int last_arr1, int last_arr2, vector<int> &nums)
    {
        if (index == nums.size())
        {
            return 1;
        }
        long long key = (long long)index * 100000000 + last_arr1 * 10000 + last_arr2;
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        int ans = 0;
        for (int i = 0; i <= nums[index]; i++)
        {
            int arr1_i = i;
            int arr2_i = nums[index] - i;
            if (arr1_i >= last_arr1 && arr2_i <= last_arr2)
            {
                ans = (ans + solve(index + 1, arr1_i, arr2_i, nums)) % MOD;
            }
        }

        memo[key] = ans;
        return ans;
    }

    int countOfPairs(vector<int> &nums)
    {
        return solve(0, 0, nums[0], nums);
    }
};
