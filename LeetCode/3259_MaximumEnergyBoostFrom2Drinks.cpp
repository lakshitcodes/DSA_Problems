#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/

class Solution
{
public:
    long long maxEnergyBoost(vector<int> &a, vector<int> &b)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = a.size();
        vector<long long> dp1(n + 1, 0), dp2(n + 2, 0);
        dp1[0] = a[0];
        dp2[0] = b[0];
        for (int i = 1; i < n; i++)
        {
            dp1[i] = max(dp1[i - 1] + a[i], dp2[i - 1]);
            dp2[i] = max(dp2[i - 1] + b[i], dp1[i - 1]);
        }
        return max(dp1[n - 1], dp2[n - 1]);
    }
};