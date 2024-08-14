#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

class Solution
{
public:
    int countPairs(vector<int> &nums, int diff)
    {
        int count = 0;
        int l = 0;
        for (int r = 1; r < nums.size(); r++)
        {
            while (r > l && nums[r] - nums[l] > diff)
            {
                l++;
            }
            count += r - l;
        }
        return count;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int pairs = countPairs(nums, mid);
            if (pairs >= k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};