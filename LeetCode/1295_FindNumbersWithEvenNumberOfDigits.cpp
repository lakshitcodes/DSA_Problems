#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        for (auto &i : nums)
        {
            ans += ((int)log10(i)) & 1;
        }
        return ans;
    }
};