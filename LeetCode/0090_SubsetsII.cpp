#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    void solve(int index, vector<int> &curr, vector<int> &nums,
               vector<vector<int>> &ans)
    {
        ans.push_back(curr);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }
            curr.push_back(nums[i]);
            solve(i + 1, curr, nums, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, nums, ans);
        return ans;
    }
};