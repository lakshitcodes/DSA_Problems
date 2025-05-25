#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-minimum-log-transportation-cost/description/

class Solution
{
public:
    long long minCuttingCost(int n, int m, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (n <= k && m <= k)
        {
            return 0;
        }
        if (m > k)
        {
            long long ans = LLONG_MAX;
            for (int i = 1; i < m; i++)
            {
                long long piece1 = i;
                long long piece2 = m - i;
                if (piece1 <= k && piece2 <= k)
                {
                    long long curr = piece1 * piece2;
                    ans = min(ans, curr);
                }
            }
            return ans;
        }
        swap(n, m);
        long long ans = LLONG_MAX;
        for (int i = 1; i < m; i++)
        {
            long long piece1 = i;
            long long piece2 = m - i;
            if (piece1 <= k && piece2 <= k)
            {
                long long curr = piece1 * piece2;
                ans = min(ans, curr);
            }
        }
        return ans;
    }
};