#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-subsequence-of-length-k-with-largest-sum/

class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back({nums[i], i});
        }
        sort(vec.rbegin(), vec.rend());
        sort(vec.begin(), vec.begin() + k, comp);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
z