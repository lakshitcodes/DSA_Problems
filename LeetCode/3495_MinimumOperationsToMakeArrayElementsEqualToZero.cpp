#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-operations-to-make-array-elements-equal-to-zero/

class Solution
{
public:
#define ll long long
    long long minOperations(vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        ll ans = 0;
        for (auto &q : queries)
        {
            ll start = q[0], end = q[1];
            ll ops = 0;

            for (ll d = 1, prev = 1; d < 17; d++)
            {
                ll curr = prev * 4LL;

                ll l = max(start, prev), r = min(end, curr - 1);

                if (r >= l)
                {
                    ops += (r - l + 1) * d;
                }
                prev = curr;
            }
            ans += (ops + 1) / 2;
        }
        return ans;
    }
};