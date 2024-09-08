#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reach-end-of-array-with-max-score/

class Solution
{
public:
    long long findMaximumScore(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        vector<long long> dp(n, 0);
        stack<int> st;

        for (int i = n - 2; i >= 0; --i)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                int j = st.top();
                dp[i] = max(dp[i], dp[j] + (long long)(j - i) * nums[i]);
            }

            dp[i] = max(dp[i], (long long)(n - 1 - i) * nums[i]);

            st.push(i);
        }
        return dp[0];
    }
};