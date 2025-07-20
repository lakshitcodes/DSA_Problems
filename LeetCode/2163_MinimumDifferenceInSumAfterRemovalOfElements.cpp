#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-difference-in-sum-after-removal-of-elements/

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<>> rq;
        int n = nums.size() / 3;
        vector<long long> diff(n + 1, 0);
        long long sum = 0;
        long long maxi = 0;

        // Storing the first n values in pq and last n values in rq
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
            rq.push(nums[2 * n + i]);
            maxi += nums[2 * n + i];
        }
        // Updating the diff vector for sum of smallest n values from index n to 2n
        for (int i = n; i <= 2 * n; i++)
        {
            diff[i - n] = sum;
            int curr = nums[i];
            if (curr >= pq.top())
            {
                continue;
            }
            sum += curr - pq.top();
            pq.pop();
            pq.push(curr);
        }

        for (int i = 2 * n - 1; i >= n - 1; i--)
        {
            diff[i - n + 1] -= maxi;
            int curr = nums[i];
            if (curr <= rq.top())
            {
                continue;
            }
            maxi += curr - rq.top();
            rq.pop();
            rq.push(curr);
        }
        return *min_element(diff.begin(), diff.end());
    }
};