#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = nums.size();
        vector<int> results(n - k + 1, -1);

        for (int i = 0; i <= n - k; ++i)
        {
            bool isConsecutiveSorted = true;
            int maxElement = nums[i];

            for (int j = i + 1; j < i + k; ++j)
            {
                if (nums[j] != nums[j - 1] + 1)
                {
                    isConsecutiveSorted = false;
                    break;
                }
                maxElement = max(maxElement, nums[j]);
            }

            if (isConsecutiveSorted)
            {
                results[i] = maxElement;
            }
        }

        return results;
    }
};