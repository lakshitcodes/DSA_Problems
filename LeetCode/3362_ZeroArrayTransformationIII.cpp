#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/zero-array-transformation-iii/

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(queries.begin(), queries.end());
        priority_queue<int> candidates;
        priority_queue<int, vector<int>, greater<>> chosen;
        int ans = 0;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < queries.size() && queries[j][0] == i)
            {
                candidates.push(queries[j][1]);
                j++;
            }
            nums[i] -= chosen.size();
            while (nums[i] > 0 && !candidates.empty() && candidates.top() >= i)
            {
                ans++;
                chosen.push(candidates.top());
                candidates.pop();
                nums[i]--;
            }
            if (nums[i] > 0)
            {
                return -1;
            }
            while (!chosen.empty() && chosen.top() == i)
            {
                chosen.pop();
            }
        }
        return queries.size() - ans;
    }
};