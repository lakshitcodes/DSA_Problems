#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/largest-divisible-subset/description/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);         // Length of largest divisible subset ending at each index
        vector<int> prevIndex(n, -1); // To track the previous index

        int maxLength = 1, endIndex = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;

                    if (dp[i] > maxLength)
                    {
                        maxLength = dp[i];
                        endIndex = i;
                    }
                }
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> result;
        while (endIndex != -1)
        {
            result.push_back(nums[endIndex]);
            endIndex = prevIndex[endIndex];
        }

        reverse(result.begin(), result.end());

        return result;
    }
};