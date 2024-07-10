#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        long long xorVal = 0;
        for (auto i : nums)
        {
            xorVal ^= i;
        }
        long long diffBit = (xorVal & (xorVal - 1)) ^ xorVal;
        int a = 0, b = 0;
        for (auto i : nums)
        {
            if (i & diffBit)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }
        return {a, b};
    }
};