#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/

class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long binpow(long long a, long long b)
    {
        a %= MOD;
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> getFinalState(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        if (m == 1)
        {
            return nums;
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        const long long lim = (1LL << 30);
        vector<long long> A(nums.begin(), nums.end());
        while (k)
        {
            auto [val, idx] = pq.top();
            pq.pop();
            if (val >= lim)
                break;
            val *= m;
            A[idx] = val;
            pq.push({val, idx});
            k--;
        }

        vector<int> ans(n);
        vector<pair<long long, int>> B;
        for (int i = 0; i < n; i++)
        {
            B.push_back({A[i], i});
        }
        sort(B.begin(), B.end());

        int tot = k / n;
        for (int i = 0; i < n; i++)
        {
            long long num = B[i].first % MOD;
            if (i < (k % n))
            {
                num *= max(1LL, binpow(m, k / n + 1));
            }
            else
            {
                num *= max(1LL, binpow(m, k / n));
            }
            num %= MOD;
            ans[B[i].second] = num;
        }
        return ans;
    }
};