#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/distribute-candies-among-children-ii/

class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0;
        int mini = max(0, n - 2 * limit);
        int maxi = min(limit, n);
        for (int i = mini; i <= maxi; i++)
        {
            int secondMin = max(0, n - i - limit);
            int secondMax = min(limit, n - i);
            ans += secondMax - secondMin + 1;
        }
        return ans;
    }
};