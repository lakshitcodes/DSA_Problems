#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/subsets/description/

class Solution
{
public:
    void subset(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        subset(nums, temp, ans, index + 1);
        temp.pop_back();
        subset(nums, temp, ans, index + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        subset(nums, temp, ans, 0);
        return ans;
    }
};

// Bit Manipulation

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>> ans(p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};