#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-special-triplets/

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, long long> left, right;
        for (int i = 1; i < nums.size(); i++)
        {
            right[nums[i]]++;
        }
        left[nums[0]]++;
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int val = nums[i] * 2;
            right[nums[i]]--;
            if (left.count(val) && right.count(val))
            {
                ans = (ans + (left[val] * right[val]) % mod) % mod;
            }
            left[nums[i]]++;
        }
        return ans;
    }
};