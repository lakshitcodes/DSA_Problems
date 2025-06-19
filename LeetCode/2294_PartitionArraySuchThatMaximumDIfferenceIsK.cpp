#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        int ans = 1;
        int mini = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - mini > k)
            {
                mini = nums[i];
                ans++;
            }
        }
        return ans;
    }
};