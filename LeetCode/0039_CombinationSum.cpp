#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/combination-sum/description/

class Solution
{
public:
    void solve(int target, int index, vector<int> &current, vector<vector<int>> &ans, vector<int> &candidates)
    {
        if (index == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }
        if (target < 0)
        {
            return;
        }
        current.push_back(candidates[index]);
        solve(target - candidates[index], index, current, ans, candidates);
        current.pop_back();
        solve(target, index + 1, current, ans, candidates);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        solve(target, 0, current, ans, candidates);
        return ans;
    }
};