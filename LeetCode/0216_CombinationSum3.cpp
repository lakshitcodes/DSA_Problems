#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/combination-sum-iii/

class Solution
{
public:
    void solve(int index, int k, int sum, vector<int> &nums, vector<int> &curr,
               vector<vector<int>> &ans)
    {
        if (sum == 0)
        {
            if (curr.size() == k)
            {
                ans.push_back(curr);
            }
            return;
        }
        if (index == 9 || sum < 0)
        {
            return;
        }

        solve(index + 1, k, sum, nums, curr, ans);
        curr.push_back(nums[index]);
        solve(index + 1, k, sum - nums[index], nums, curr, ans);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, k, n, nums, curr, ans);
        return ans;
    }
};