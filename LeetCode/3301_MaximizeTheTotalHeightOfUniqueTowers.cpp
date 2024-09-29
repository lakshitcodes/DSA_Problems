#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/

class Solution
{
public:
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(maximumHeight.rbegin(), maximumHeight.rend());
        long long ans = maximumHeight[0];
        for (int i = 1; i < maximumHeight.size(); i++)
        {
            int possible = min(maximumHeight[i], maximumHeight[i - 1] - 1);
            if (possible <= 0)
            {
                return -1;
            }
            ans += possible;
            maximumHeight[i] = possible;
        }
        return ans;
    }
};