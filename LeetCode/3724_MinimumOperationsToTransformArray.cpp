#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-operations-to-transform-array/

class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        long long minDiff = INT_MAX;
        long long lastEle = nums2.back();
        for (int i = 0; i < nums1.size(); i++)
        {
            ans += abs(nums1[i] - nums2[i]);

            if ((lastEle > nums1[i] && lastEle < nums2[i]) || (lastEle < nums1[i] && lastEle > nums2[i]))
            {
                minDiff = 0;
            }
            minDiff = min(abs(lastEle - nums1[i]), minDiff);
            minDiff = min(abs(lastEle - nums2[i]), minDiff);
        }
        return ans + minDiff + 1;
    }
};