#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int M = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(2 * M + *max_element(nums.begin(), nums.end()) + 2, vector<int>(M + 1, 0));
        int res = 1;

        for (int i = n - 1; i >= 0; --i) {
            vector<int> curr(M + 1, 0);
            int l = 1;

            for (int diff = 0; diff <= M; ++diff) {
                int minusIndex = nums[i] - diff;
                int plusIndex = nums[i] + diff;

                if (minusIndex >= 0) {
                    l = max(l, 1 + dp[minusIndex][diff]);
                }
                if (plusIndex < dp.size()) {
                    l = max(l, 1 + dp[plusIndex][diff]);
                }

                curr[diff] = l;
                res = max(res, l);
            }

            for (int diff = 0; diff <= M; ++diff) {
                dp[nums[i]][diff] = max(dp[nums[i]][diff], curr[diff]);
            }
        }

        return res;
    }
};
