#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/build-array-from-permutation/

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};