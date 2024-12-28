#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

// My Approach (TLE)
class Solution {
public:
    void solve(int index, int k, const vector<int>& sums, vector<int>& curr, int& maxSum, vector<int>& result) {
        // Base case for correct answers
        if (curr.size() == 3) {
            int currentSum = sums[curr[0]] + sums[curr[1]] + sums[curr[2]];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = curr;
            }
            return;
        }
        // Out of bounds
        if (index >= sums.size()) {
            return;
        }
        // Include ki call
        curr.push_back(index);
        solve(index + k, k, sums, curr, maxSum, result);
        curr.pop_back();
        // Exclude ki call
        solve(index + 1, k, sums, curr, maxSum, result);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=nums.size();
        vector<int> sums(n-k+1,0);
        for(int i=0;i<k;i++){
            sums[0]+=nums[i];
        }
        for(int i=1;i<=n-k;i++){
            sums[i]=sums[i-1]-nums[i-1]+nums[i+k-1];
        }

        // Recursively find the answer
        vector<int> result;
        vector<int> curr;
        int maxSum = 0;
        solve(0, k, sums, curr, maxSum, result);

        return result;
    }
};


// Optimized Approach
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1, 0);
        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);

        // Step 1: Calculate sliding window sums
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        sums[0] = sum;
        for (int i = 1; i <= n - k; ++i) {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            sums[i] = sum;
        }

        // Step 2: Calculate maximum sums from the left
        int bestLeftIdx = 0;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > sums[bestLeftIdx]) {
                bestLeftIdx = i;
            }
            left[i] = bestLeftIdx;
        }

        // Step 3: Calculate maximum sums from the right
        int bestRightIdx = sums.size() - 1;
        for (int i = sums.size() - 1; i >= 0; --i) {
            if (sums[i] >= sums[bestRightIdx]) { // >= to ensure rightmost index is preferred
                bestRightIdx = i;
            }
            right[i] = bestRightIdx;
        }

        // Step 4: Find the maximum sum using middle subarray
        vector<int> result(3, -1);
        int maxSum = 0;
        for (int mid = k; mid < sums.size() - k; ++mid) {
            int l = left[mid - k];      // Best left subarray
            int r = right[mid + k];    // Best right subarray
            int totalSum = sums[l] + sums[mid] + sums[r];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, mid, r};
            }
        }

        return result;
    }
};
