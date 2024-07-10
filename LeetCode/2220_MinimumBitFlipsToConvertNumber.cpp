#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int diffBits = start ^ goal;
        if (diffBits == 0)
        {
            return 0;
        }
        return __builtin_popcount(diffBits);
    }
};