#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for (int i = 0; i < k; ++i)
        {
            auto min_it = std::min_element(nums.begin(), nums.end());
            int min_index = std::distance(nums.begin(), min_it);
            nums[min_index] *= multiplier;
        }
        return nums;
    }
};