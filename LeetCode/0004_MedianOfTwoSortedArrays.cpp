#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

// Approach 1: Merge the two arrays and then find the median
// Time Complexity : O(n+m)
// Space Complexity : O(n+m)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            nums[k++] = nums1[i++];
        }
        else
        {
            nums[k++] = nums2[j++];
        }
    }
    while (i < n)
    {
        nums[k++] = nums1[i++];
    }
    while (j < m)
    {
        nums[k++] = nums2[j++];
    }
    int mid = (n + m) / 2;
    if ((n + m) % 2 == 0)
    {
        return (nums[mid - 1] + nums[mid]) / 2.0;
    }
    else
    {
        return nums[mid];
    }
}

// Approach 2: Binary Search
// Time Complexity : O(log(min(n,m)))
// Space Complexity : O(1)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0, r = n;
        int leftSize = (n + m + 1) / 2;
        while (l <= r)
        {
            int mid1 = (l + r) >> 1;
            int mid2 = leftSize - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n)
            {
                r1 = nums1[mid1];
            }
            if (mid2 < m)
            {
                r2 = nums2[mid2];
            }
            if (mid1 - 1 >= 0)
            {
                l1 = nums1[mid1 - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n + m) % 2)
                {
                    return max(l1, l2);
                }
                else
                {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }

            if (l1 > r2)
            {
                r = mid1 - 1;
            }
            else
            {
                l = mid1 + 1;
            }
        }
        return 0;
    }
};