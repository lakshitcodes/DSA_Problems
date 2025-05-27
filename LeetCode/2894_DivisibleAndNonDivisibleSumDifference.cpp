#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = n * (n + 1) / 2;
        for (int i = m; i <= n; i += m)
        {
            ans -= 2 * i;
        }
        return ans;
    }
};