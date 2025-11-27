#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/

#define ll long long
class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        ll prefSum = 0;
        ll subMax = LLONG_MIN;
        vector<ll> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefSum += nums[i];
            subMax = max(subMax, prefSum - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k], prefSum);
        }

        return subMax;
    }
};