#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for (int i = 0; i < 61; i++)
        {
            long long target = (long long)num1 - (long long)i * (long long)num2;
            bitset<64> bits(target);
            if (target >= 0 && bits.count() <= i && i <= target)
            {
                return i;
            }
        }
        return -1;
    }
};