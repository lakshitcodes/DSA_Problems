#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long a = 0, b = 0;
        long long sum1 = 0, sum2 = 0;
        for (auto &i : nums1)
        {
            a += (i == 0);
            sum1 += i;
        }
        for (auto &i : nums2)
        {
            b += (i == 0);
            sum2 += i;
        }
        sum1 += a;
        sum2 += b;
        if ((sum2 > sum1 && a == 0) || (sum1 > sum2 && b == 0))
        {
            return -1;
        }
        return max(sum1, sum2);
    }
};