#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-maximum-sum-of-node-values/

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long totalSum = 0;
        int pos = INT_MAX, neg = INT_MIN;
        int count = 0;
        for (auto &i : nums)
        {
            int newVal = i ^ k;
            totalSum += i;
            int change = newVal - i;
            if (change > 0)
            {
                count++;
                totalSum += change;
                pos = min(pos, change);
            }
            else
            {
                neg = max(neg, change);
            }
        }
        if (count % 2 == 0)
        {
            return totalSum;
        }
        return max(totalSum - pos, totalSum + neg);
    }
};