#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution
{
public:
#define MOD 1000000007
    int sumSubarrayMins(vector<int> &arr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Calculate left array
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        // Calculate right array
        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long left_count = i - left[i];
            long long right_count = right[i] - i;
            ans += (left_count * right_count % MOD) * arr[i] % MOD;
            ans %= MOD;
        }
        return ans;
    }
};
