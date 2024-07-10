#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ones = 0, twos = 0;
        for (int num : nums)
        {
            ones = ones ^ (num & ~twos);
            twos = twos ^ (num & ~ones);
        }
        return ones;
    }
};