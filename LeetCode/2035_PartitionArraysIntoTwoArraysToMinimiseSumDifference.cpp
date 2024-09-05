#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Here I am using a meet in the middle approach
        // https://www.youtube.com/watch?v=45TkgKy0GS0
        // Use the link above to brushup
        // So here we want to minimize , sum1-sum2
        // Now sum1+sum2 = totalSum
        // So basically we need to minimise -> totalSum-2*sum2
        // We will divide the array into two equal parts of length n , and generate all possible sums using those two arrays
        // We will store the sums possible for subarrays for specific size seperately of both the half arrays
        // Then for example if we have taken sum of 3 elements from the left half , then we will take the sum of n/2 - 3 elements from the right half and then process it .

        int N = nums.size(), res = 0;
        // totalSum
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = N / 2;

        // Vectors to store the sum in left and right half by considering different amount of numbers
        vector<vector<int>> left(n + 1), right(n + 1);

        // Storing all possible sums in left and right part
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int sz = 0, l = 0, r = 0;
            // sz stores the number of elements considered
            for (int i = 0; i < n; i++)
            {
                // Checking if that element is to be considered in this iteration using mask
                if (mask & (1 << i))
                {
                    l += nums[i];
                    r += nums[i + n];
                    sz++;
                }
            }
            // Storing the sum of size sz
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        // Now since we have populated the sums of the subsets of the left and right parts,now finding answer using them
        // Now lets say the part from right has sum a and left has sum as b
        // then totalSum-2*(a+b) has to be minimized i,e
        // totalSum - 2a / 2 >=b
        // For one particular a we have to find b

        // Taking all elements from left or right
        res = min(abs(sum - 2 * left[n][0]), abs(sum - 2 * right[n][0]));

        // iterating over left part
        for (int sz = 1; sz < n; sz++)
        {
            // sorting on right side so that we can use binary search later
            sort(right[n - sz].begin(), right[n - sz].end());
            for (auto &a : left[sz])
            {
                int b = (sum - 2 * a) / 2;
                int rsz = n - sz;

                // binary search over right part
                auto itr = lower_bound(right[rsz].begin(), right[rsz].end(), b);
                if (itr != right[rsz].end())
                {
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }
                if (itr != right[rsz].begin())
                {
                    auto it = itr;
                    it--;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }
            }
        }
        return res;
    }
};