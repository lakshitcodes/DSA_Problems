#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-number-of-balanced-permutations/

class Solution
{
public:
    static const int mod = 1e9 + 7;
    using ll = long long;
    vector<ll> fact, inv, invFact;

    void precompute(int n)
    {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;

        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; i++)
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;

        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            invFact[i] = invFact[i - 1] * inv[i] % mod;
    }

    int countBalancedPermutations(string num)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int sum = 0;
        int n = num.length();
        for (auto &i : num)
        {
            sum += i - '0';
        }
        if (sum & 1)
        {
            return 0;
        }
        precompute(n);
        int halfSum = sum / 2;
        int halfLen = n / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1, 0));
        dp[0][0] = 1;
        vector<int> digits(10, 0);
        for (auto &d : num)
        {
            int dig = d - '0';
            digits[dig]++;
            for (int i = halfSum; i >= dig; i--)
            {
                for (int j = halfLen; j > 0; j--)
                {
                    dp[i][j] = (dp[i][j] + dp[i - dig][j - 1]) % mod;
                }
            }
        }

        ll ans = dp[halfSum][halfLen];
        ans = (ans * fact[halfLen]) % mod;
        ans = (ans * fact[n - halfLen]) % mod;
        for (auto &i : digits)
        {
            ans = (ans * invFact[i]) % mod;
        }
        return ans;
    }
};