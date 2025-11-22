#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        for (auto &i : nums)
        {
            i %= 3;
        }
        for (auto i : nums)
        {
            if (i)
                ans += min(abs(3 - i), i);
        }
        return ans;
    }
};