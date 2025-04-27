#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> groups(n, 0);
        groups[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] <= maxDiff)
            {
                groups[i] = groups[i - 1];
            }
            else
            {
                groups[i] = groups[i - 1] + 1;
            }
        }
        vector<bool> ans;
        for (auto &i : queries)
        {
            if (groups[i[0]] == groups[i[1]])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};